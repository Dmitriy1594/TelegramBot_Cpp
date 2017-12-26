#include "api.hpp"
#include "utils.hpp"
#include <tgbot/tgbot.h>
//
using namespace std;
using namespace TgBot;
using namespace Utils;
//----------------------
#include "library.hpp"
#include "math.hpp"
#include "Al.hpp"
#include "En.hpp"
// для выхода
void exitlibrary(Bot& bot, Message::Ptr message);
//
void library(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    // выводим сообщение
    std::string answer = Utils::fromLocale("Добро пожаловать в библиотеку!");
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
    button0->text = Utils::fromLocale("Математический анализ");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_0lib";
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
    button1->text = Utils::fromLocale("Алгоритмические языки");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_1lib";
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
    button2->text = Utils::fromLocale("Английский язык");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_2lib";
    // добавляем кнопки на строку
    row2.push_back(button2);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row2);
    //
    answer = Utils::fromLocale("Выберите тематику литературы:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}
//
// 0
void onClickButton0Lib(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 1"));
    math(bot, query->message);
}
// 1
void onClickButton1Lib(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 2"));
    AL(bot, query->message);
}
// 2
void onClickButton2Lib(Bot& bot, CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Вы нажали на кнопку 3"));
    En(bot, query->message);
}
//
// exitclibrary звпускается после вывода на экран
void exitlibrary(Bot& bot, Message::Ptr message) {
    // exit
    // создаем объект клавиатура
    InlineKeyboardMarkup::Ptr keyboardexit(new InlineKeyboardMarkup);
    // создаем вектор
    vector<InlineKeyboardButton::Ptr> rowexit;
    // создаем кнопку
    InlineKeyboardButton::Ptr buttonexit(new InlineKeyboardButton);
    // текст кнопки
    buttonexit->text = Utils::fromLocale("Выход из режима");
    // текстовый идентификатор кнопки
    buttonexit->callbackData = "id_button_exitlib";
    // добавляем кнопки на строку
    rowexit.push_back(buttonexit);
    // добавляем строку кнопок в клавиатуру
    keyboardexit->inlineKeyboard.push_back(rowexit);
    // result
    // отсылаем сообщение вместе с клавиатурой
    std::string answer = Utils::fromLocale("Выход");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboardexit, "Markdown");
}
// описание выхода
void onClickbuttonexitlib(Bot& bot, CallbackQuery::Ptr query) {
    onCommandKeyboard(bot, query->message);
}
//
