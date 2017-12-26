#include "api.hpp"
#include "utils.hpp"
#include <tgbot/tgbot.h>
//
using namespace std;
using namespace TgBot;
using namespace Utils;
//----------------------
#include "calculator.hpp"
//

long double func0(const long double& num1,
                  const long double& num2, std::string& operation) {
    long double result = 0;
    if (operation == "+") {
        result = num1 + num2;
    } else if (operation == "-") {
        result = num1 - num2;
    } else if (operation == "/") {
        result = num1 / num2;
    } else if (operation == "*") {
        result = num1 * num2;
    } else if (operation == "^") {
        result = std::pow(num1, num2);
    } else if (operation == "%") {
        result = static_cast<int>(num1) % static_cast<int>(num2);
    }
    return result;
}

long double func1(const long double& num1,
                  const long double& num2, std::string& operation) {
    long double result = 0;
    if (operation == "sqrt") {
        result = std::sqrt(num1);
    } else if (operation == "ln") {
        result = std::log(num1);
    } else if (operation == "lg") {
        result = (std::log(num1)) / (std::log(10));
    } else if (operation == "log") {
        result = (std::log(num2)) / (std::log(num1));
    }
    return result;
}

long double func2(const long double& num1, std::string& operation) {
    long double result = 0;
    if (operation == "sin") {
        result = std::sin(num1);
    } else if (operation == "cos") {
        result = std::cos(num1);
    } else if (operation == "tg") {
        result = std::tan(num1);
    } else if (operation == "ctg") {
        result = std::pow(std::tan(num1), -1);
    } else if (operation == "sec") {
        result = std::pow(std::cos(num1), -1);
    } else if (operation == "cosec") {
        result = std::pow(std::sin(num1), -1);
    }
    return result;
}

long double func3(const long double& num1, std::string& operation) {
    long double result = 0;
    if (operation == "arcsin") {
        result = std::asin(num1);
    } else if (operation == "arccos") {
        result = std::acos(num1);
    } else if (operation == "arctg") {
        result = std::atan(num1);
    } else if (operation == "arcctg") {
        result = (M_PI_2 - std::atan(num1));
    } else if (operation == "arcsec") {
        result = std::acos(std::pow(num1, -1));
    } else if (operation == "arccosec") {
        result = std::asin(std::pow(num1, -1));
    }
    return result;
}

std::vector<std::string> loadFromFile(const std::string& filename) {
    std::vector<std::string> consts = {};
    std::fstream fl(filename, std::ios_base::in);
    std::string str = "";
    while (!fl.eof()) {
        std::getline(fl, str);
        consts.push_back(str);
        str = {};
    }
    return consts;
}

// разделение сообщение от пользователя на элементы строк в vector
// 0
std::vector<std::string> splitstr0(const std::string& str) {
    char sep = ' ';
    char sep1 = '+';
    char sep2 = '-';
    char sep3 = '*';
    char sep4 = '/';
    char sep5 = '^';
    char sep6 = '%';
    std::string arr;
    std::vector<std::string> array;
    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] != sep) && (str[i] != sep1) && (str[i] != sep2)
            && (str[i] != sep3) && (str[i] != sep4)
            && (str[i] != sep5) && (str[i] != sep6)) {
            arr.push_back(str[i]);
        } else {
            if (str[i] != ' ') {
                array.push_back(arr);
                arr.erase(arr.begin(), arr.end());
                //
                arr.push_back(str[i]);
                array.push_back(arr);
                arr.erase(arr.begin(), arr.end());
            }
        }
        if ((str.length() - i) == 1) {
            array.push_back(arr);
        }
    }
    return array;
}
// для 1
std::vector<std::string> splitstr1(std::string& str) {
    char sep = ' ';
    std::string arr;
    std::vector<std::string> array;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != sep) {
            arr.push_back(str[i]);
        } else {
            array.push_back(arr);
            arr.erase(arr.begin(), arr.end());
        }
        if ((str.length() - i) == 1) {
            array.push_back(arr);
        }
    }
    return array;
}

//
void calculator(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    // выводим сообщение
    std::string answer = Utils::fromLocale("Добро пожаловать в калькулятор!");
    bot.getApi().sendMessage(message->chat->id, answer);
    //
    // создаем объект клавиатура
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    // 0
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row0;
    // создаем кнопку
    InlineKeyboardButton::Ptr button0(new InlineKeyboardButton);
    // текст кнопки
    button0->text = "(+, -, /, *, ^, %)";
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_0";
    // добавляем кнопки на строку
    row0.push_back(button0);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row0);
    //
    // 1
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row1;
    // создаем кнопку
    InlineKeyboardButton::Ptr button1(new InlineKeyboardButton);
    // текст кнопки
    button1->text = "(sqrt, log, ln, lg)";
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_1";
    // добавляем кнопки на строку
    row1.push_back(button1);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row1);
    //
    // 2
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row2;
    // создаем кнопку
    InlineKeyboardButton::Ptr button2(new InlineKeyboardButton);
    // текст кнопки
    button2->text = Utils::fromLocale("(sin, cos, tg, ctg, sec, cosec)");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_2";
    // добавляем кнопки на строку
    row2.push_back(button2);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row2);
    //
    // 3
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row3;
    // создаем кнопку
    InlineKeyboardButton::Ptr button3(new InlineKeyboardButton);
    // текст кнопки
    button3->text = Utils::fromLocale("(arccos, arcsin, arctg, arcctg, arcsec, arccosec)");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_3";
    // добавляем кнопки на строку
    row3.push_back(button3);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row3);
    //
    // 4
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> row4;
    // создаем кнопку
    InlineKeyboardButton::Ptr button4(new InlineKeyboardButton);
    // текст кнопки
    button4->text = Utils::fromLocale("Вывести все избранные константы");
    // текстовый идентификатор кнопки
    button4->callbackData = "id_button_4";
    // добавляем кнопки на строку
    row4.push_back(button4);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row4);
    // result
    // отсылаем сообщение вместе с клавиатурой
    answer = Utils::fromLocale("Выберите режим калькулятора:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
    answer = {};
}

// 0
void onClickButton0(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 0"));
    std::string answer0 = Utils::fromLocale("Введите два числа(через пробел) и операцию, которую надо совершить над ними:");
    bot.getApi().sendMessage(query->message->chat->id, answer0);
    //
    WAITING_MESSAGE = 0;
}
// 1
void onClickButton1(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 1"));
    std::string answer1 = Utils::fromLocale("Введите операцию:");
    bot.getApi().sendMessage(query->message->chat->id, answer1);
    //
    WAITING_MESSAGE = 1;
}
// 2
void onClickButton2(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 2"));
    std::string answer2 = Utils::fromLocale("Введите операцию и число (десятичную часть числа пи), "
                                            "которую надо совершить над ним: (Пример: sin 0.25 преобразуется в sin pi/4)");
    bot.getApi().sendMessage(query->message->chat->id, answer2);
    //
    WAITING_MESSAGE = 2;
}
// 3
void onClickButton3(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 3"));
    std::string answer3 = Utils::fromLocale("Введите операцию и число, которую надо совершить над ним:");
    bot.getApi().sendMessage(query->message->chat->id, answer3);
    //
    WAITING_MESSAGE = 3;
}
// 4
void onClickButton4(Bot& bot, CallbackQuery::Ptr query) {
    // файл с константами
    const std::string filename = "const.txt";
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 4"));
    std::vector<std::string> consts = loadFromFile(filename);
    std::string answer4 = {};
    for (auto con : consts) {
        answer4 += (con + "\n");
    }
    bot.getApi().sendMessage(query->message->chat->id, answer4);
    exitcalculator(bot, query->message);
}
//
// exitcalculator звпускается после вывода на экран ответа или ошибки
void exitcalculator(Bot& bot, Message::Ptr message) {
    // выход или продолжить ???
    // exit
    // создаем объект клавиатура
    InlineKeyboardMarkup::Ptr keyboardexit(new InlineKeyboardMarkup);
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> rowexit;
    // создаем кнопку
    InlineKeyboardButton::Ptr buttonexit(new InlineKeyboardButton);
    // текст кнопки
    buttonexit->text = Utils::fromLocale("Выход");
    // текстовый идентификатор кнопки
    buttonexit->callbackData = "id_button_exit";
    // добавляем кнопки на строку
    rowexit.push_back(buttonexit);
    // добавляем строку кнопок в клавиатуру
    keyboardexit->inlineKeyboard.push_back(rowexit);
    // contine
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> rowcontinue;
    // создаем кнопку
    InlineKeyboardButton::Ptr buttoncont(new InlineKeyboardButton);
    // текст кнопки
    buttoncont->text = Utils::fromLocale("Продолжить");
    // текстовый идентификатор кнопки
    buttoncont->callbackData = "id_button_continue";
    // добавляем кнопки на строку
    rowcontinue.push_back(buttoncont);
    // добавляем строку кнопок в клавиатуру
    keyboardexit->inlineKeyboard.push_back(rowcontinue);
    // result
    // отсылаем сообщение вместе с клавиатурой
    std::string answer = Utils::fromLocale("Выход или продолжить?");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboardexit, "Markdown");
}
// описание выхода
void onClickbuttonexit(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Выход"));
    onCommandKeyboard(bot, query->message);
}
// описание продолжения
void onClickbuttoncont(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Продолжить"));
    calculator(bot, query->message);
}
//
