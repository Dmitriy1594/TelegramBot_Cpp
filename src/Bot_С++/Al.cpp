#include "api.hpp"
#include "utils.hpp"
#include <tgbot/tgbot.h>
//
using namespace std;
using namespace TgBot;
using namespace Utils;
//----------------------
#include "Al.hpp"
#include "math.hpp"
//
void AL(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    std::string answer = Utils::fromLocale("Добро пожаловать в библиотеку программиста!\n"
                                           "Здесь вы найдете полезные книги.");
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
    button0->text = Utils::fromLocale("С/С++");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_02";
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
    button1->text = Utils::fromLocale("Python");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_12";
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
    button2->text = Utils::fromLocale("Java");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_22";
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
    button3->text = Utils::fromLocale("JS");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_32";
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
    button4->text = Utils::fromLocale("Assembler");
    // текстовый идентификатор кнопки
    button4->callbackData = "id_button_42";
    // добавляем кнопки на строку
    row4.push_back(button4);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row4);
    //
    answer = Utils::fromLocale("Выберите тематику книги:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}
//
// 0
void onClickButton02(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Язык С"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Стивен Прата - Язык программирования C"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Язык_программирования_C_Лекции_и.pdf", "Al/pdf"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Бен Клеменс - Язык С в XXI веке"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Бен Клеменс - Язык С в XXI веке.pdf", "Al/pdf"));
    //--
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Язык С++"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Bjarne Stroustrup - The C++ Programming Language"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Bjarne_Stroustrup_-_The_C__Programming_Languag.pdf", "Al/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 1
void onClickButton12(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Пол Бэрри - Изучаем программирование на Python"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Пол_Бэрри_Изучаем_программирование.pdf", "Al/pdf"));
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Mark Lutts - Программирование на Python"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Mark_Lutts_Programmirovanie_na_Python.pdf", "Al/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 2
void onClickButton22(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("M MakGrat - Программирование на Java"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("M_MakGrat___Programmirovanie_na_.pdf", "Al/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 3
void onClickButton32(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Васильев А - Программирование на JS"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Vasilyev_A_Programmirovanie_na_JS.pdf", "Al/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 4
void onClickButton42(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Рудольф Марек - Assembler на примерах"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Рудольф_Марек_Assembler_на_примерах.pdf", "Al/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
