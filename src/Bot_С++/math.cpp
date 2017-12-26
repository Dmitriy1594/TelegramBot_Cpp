#include "api.hpp"
#include "utils.hpp"
#include <tgbot/tgbot.h>
//
using namespace std;
using namespace TgBot;
using namespace Utils;
//----------------------
#include "math.hpp"

// для выхода
void exitmath(Bot& bot, Message::Ptr message);
//
void math(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    std::string answer = Utils::fromLocale("Добро пожаловать в математический раздел библиотеки!\n"
                                           "Тут вы найдете пару интересных книг.");
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
    button0->text = Utils::fromLocale("А.Бенджамин, М.Шермер Магия чисел");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_01";
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
    button1->text = Utils::fromLocale("Б.П.Демидович Сборник задач и упражнений");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_11";
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
    button2->text = Utils::fromLocale("Курс дифференциального и интегрального исчисления");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_21";
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
    button3->text = Utils::fromLocale("Khaggarti R - Дискретная математика для программистов");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_31";
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
    button4->text = Utils::fromLocale("Barbara Oakli - Думай как математик");
    // текстовый идентификатор кнопки
    button4->callbackData = "id_button_41";
    // добавляем кнопки на строку
    row4.push_back(button4);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row4);
    //
    answer = Utils::fromLocale("Выберите книгу:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}
//
// 0
void onClickButton01(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("А.Бенджамин,М.Шермер Магия чисел"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("А_Бенджамин,_М_Шермер_Магия_чисел.pdf", "math/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 1
void onClickButton11(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Б.П.Демидович Сборник задач и упражнений"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Б_П_Демидович_Сборник_задач_и_упражнений.pdf", "math/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 2
void onClickButton21(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Курс дифференциального и интегрального исчисления"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Курс_дифференциального_и_интегрального (2).djvu", "math/djvu"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Курс_дифференциального_и_интегрального (3).djvu", "math/djvu"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Курс_дифференциального_и_интегрального.djvu", "math/djvu"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 3
void onClickButton31(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Khaggarti R - Дискретная математика для программистов"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Khaggarti_R_Diskretnaya_matematika_dlya_programmistov.pdf", "math/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 4
void onClickButton41(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Barbara Oakli - Думай как математик"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Barbara_Oakli_-_Dumay_kak_matematik.pdf", "math/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
//
// exitmath звпускается после вывода на экран
void exitmath(Bot& bot, Message::Ptr message) {
    // exit
    // создаем объект клавиатура
    InlineKeyboardMarkup::Ptr keyboardexit(new InlineKeyboardMarkup);
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> rowexit;
    // создаем кнопку
    InlineKeyboardButton::Ptr buttonexit(new InlineKeyboardButton);
    // текст кнопки
    buttonexit->text = Utils::fromLocale("Назад");
    // текстовый идентификатор кнопки
    buttonexit->callbackData = "id_button_exitmath";
    // добавляем кнопки на строку
    rowexit.push_back(buttonexit);
    // добавляем строку кнопок в клавиатуру
    keyboardexit->inlineKeyboard.push_back(rowexit);
    // result
    // отсылаем сообщение вместе с клавиатурой
    std::string answer = Utils::fromLocale("Назад");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboardexit, "Markdown");
}
// описание выхода
void onClickbuttonexitmath(Bot& bot, CallbackQuery::Ptr query) {
    library(bot, query->message);
}
//
