#include "api.hpp"
#include "utils.hpp"
#include "keyboard.hpp"
// calculator
#include "calculator.hpp"
#include "library.hpp"
#include "links.hpp"
#include "math.hpp"
#include "Al.hpp"
#include "En.hpp"

// Файл, для демонстрации работы с клавиатурой

using namespace std;
using namespace TgBot;
using namespace Utils;


// Функция для демонстрации работы с Inline Keyboard
// https://core.telegram.org/bots/2-0-intro
// Для вызова необходимо прислать сообщение /keyboard или /help
void onCommandKeyboard(Bot& bot, Message::Ptr message)
{
    // Создаем объект клавиатуры
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    
    vector<InlineKeyboardButton::Ptr> rowfirst;
    InlineKeyboardButton::Ptr buttonZero(new InlineKeyboardButton);
    buttonZero->text = fromLocale("Библиотека");
    buttonZero->callbackData = "id_button_lib";
    rowfirst.push_back(buttonZero);
    keyboard->inlineKeyboard.push_back(rowfirst);

    // создаем новую строку в клавиалуре
    // обычный вектор
    vector<InlineKeyboardButton::Ptr> row0;

    // создаем кнопку
    InlineKeyboardButton::Ptr buttonOne(new InlineKeyboardButton);
    // текс кнопки
    buttonOne->text = fromLocale("Калькулятор");
    // текстовый идентификатор кнопки
    // при нажатии на кнопку будет приходить именно этот текст
    // смотри функцию getAllCallbacks
    buttonOne->callbackData = "id_button_one";

    // добавляем кнопки на строку
    row0.push_back(buttonOne);

    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row0);

    // создаем еще строку в клавиатуре
    vector<InlineKeyboardButton::Ptr> row2;
    //
    InlineKeyboardButton::Ptr buttonTwo(new InlineKeyboardButton);
    // чтобы вывести русский текст, надо использовать функцию fromLocale
    buttonTwo->text = fromLocale("Полезные ссылки для программиста");
    buttonTwo->callbackData = "id_button_two";
    row2.push_back(buttonTwo);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row2);

    // отсылаем сообщение вместе с клавиатурой
    std::string answer = Utils::fromLocale("Выберите режим помощника, нажав на соответствующую кнопку:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}

//
void onClickButtonZero(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 0"));
    library(bot, query->message);
}
// Функция вызывается каждый раз, когда нажимают на кнопку 1
// (а точнее с callbackData == id_button_one)
void onClickButtonOne(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 1"));
    calculator(bot, query->message);
}

// Функция вызывается каждый раз, когда нажимают на кнопку 2
void onClickButtonTwo(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажили на кнопку 2"));
    links(bot, query->message);
}

//
// Регистрируем наши кнопки
std::map<std::string, std::function<void(Bot&, CallbackQuery::Ptr)>> getAllCallbacks()
{
    // Ключом является идентификатор кнопки
    // значением является функция-обработчик кнопки
    // т.е. при нажатии на кнопку с идентификатором, произойдет вызов соответствующей функции
    // Например, при нажании на кнопку с идентификатором id_button_one вызовется функция onClickButtonOne
    std::map<std::string, std::function<void(Bot&, CallbackQuery::Ptr)>> callbacks =
    {
        /*РЕЖИМ ПОМОЩНИКА*/
        {"id_button_lib", onClickButtonZero},
        {"id_button_one", onClickButtonOne},
        {"id_button_two", onClickButtonTwo},
        /*БИБЛИОТЕКА*/
        {"id_button_0lib", onClickButton0Lib},
        {"id_button_1lib", onClickButton1Lib},
        {"id_button_2lib", onClickButton2Lib},
        {"id_button_exitlib", onClickbuttonexitlib},
        /*LIBRARY->MATH*/
        {"id_button_01", onClickButton01},
        {"id_button_11", onClickButton11},
        {"id_button_21", onClickButton21},
        {"id_button_31", onClickButton31},
        {"id_button_41", onClickButton41},
        {"id_button_exitmath", onClickbuttonexitmath},
        /*LIBRARY->AL*/
        {"id_button_02", onClickButton02},
        {"id_button_12", onClickButton12},
        {"id_button_22", onClickButton22},
        {"id_button_32", onClickButton32},
        {"id_button_42", onClickButton42},
        /*LIBRARY->En*/
        {"id_button_03", onClickButton03},
        {"id_button_13", onClickButton13},
        {"id_button_23", onClickButton23},
        {"id_button_33", onClickButton33},
        /*КАЛЬКУЛЯТОР*/
        {"id_button_0", onClickButton0},
        {"id_button_1", onClickButton1},
        {"id_button_2", onClickButton2},
        {"id_button_3", onClickButton3},
        {"id_button_4", onClickButton4},
        {"id_button_exit", onClickbuttonexit},
        {"id_button_continue", onClickbuttoncont}
    };
    return callbacks;
}
