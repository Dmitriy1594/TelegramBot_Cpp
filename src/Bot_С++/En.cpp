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
#include "En.hpp"
//
void En(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    std::string answer = Utils::fromLocale("Добро пожаловать в библиотеку по английскому языку!\n"
                                           "Здесь вы найдете очень полезные книги.");
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
    button0->text = Utils::fromLocale("4 English Grammar in Use");
    // текстовый идентификатор кнопки
    button0->callbackData = "id_button_03";
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
    button1->text = Utils::fromLocale("Dictionary for Murphy поурочный словарь");
    // текстовый идентификатор кнопки
    button1->callbackData = "id_button_13";
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
    button2->text = Utils::fromLocale("Evans V., Dooley J. - New Round Up 5 Students' Book");
    // текстовый идентификатор кнопки
    button2->callbackData = "id_button_23";
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
    button3->text = Utils::fromLocale("English Grammar in Use - Grammar_Reference");
    // текстовый идентификатор кнопки
    button3->callbackData = "id_button_33";
    // добавляем кнопки на строку
    row3.push_back(button3);
    // добавляем строку кнопок в клавиатуру
    keyboard->inlineKeyboard.push_back(row3);
    //
    answer = Utils::fromLocale("Выберите книгу:");
    bot.getApi().sendMessage(message->chat->id, answer, false, 0, keyboard, "Markdown");
}

// 0
void onClickButton03(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("4 English Grammar in Use"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("4_English_Grammar_in_Use_-_Supplementary_Exerc.pdf", "En/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 1
void onClickButton13(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Dictionary for Murphy поурочный словарь"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("8_Dictionary_for_Murphy_pourochny_slovar_k_M.pdf", "En/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 2
void onClickButton23(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("Evans V., Dooley J. - New Round Up 5 Students' Book"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("Evans V., Dooley J. - New Round Up 5 Students' Book.pdf", "En/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
// 3
void onClickButton33(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query) {
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("English Grammar in Use - Grammar_Reference"));
    bot.getApi().sendDocument(query->message->chat->id, InputFile::fromFile("5_English_Grammar_in_Use_-_Grammar_Reference.pdf", "En/pdf"));
    exitmath(bot, query->message);
    exitlibrary(bot, query->message);
}
