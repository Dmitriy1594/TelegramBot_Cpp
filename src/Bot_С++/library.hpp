#ifndef library_hpp
#define library_hpp

#include <functional>
#include <map>
#include <tgbot/tgbot.h>
//
#include "keyboard.hpp"
//
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#endif /* library_hpp */
// start
void library(TgBot::Bot& bot, TgBot::Message::Ptr message);
// generate
void onClickButton0Lib(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton1Lib(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton2Lib(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
// exit
void exitlibrary(TgBot::Bot& bot, TgBot::Message::Ptr message);
void onClickbuttonexitlib(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
