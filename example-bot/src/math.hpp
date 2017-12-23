#ifndef math_hpp
#define math_hpp

#include <functional>
#include <map>
#include <tgbot/tgbot.h>
//
#include "keyboard.hpp"
#include "library.hpp"
//
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#endif /* math_hpp */
// start
void math(TgBot::Bot& bot, TgBot::Message::Ptr message);
// generate
void onClickButton01(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton11(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton21(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton31(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton41(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
// exit
void exitmath(TgBot::Bot& bot, TgBot::Message::Ptr message);
void onClickbuttonexitmath(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
