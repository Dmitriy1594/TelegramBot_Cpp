#ifndef calculator_hpp
#define calculator_hpp

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
//---GLOBAL---------
extern int WAITING_MESSAGE;
//-----------------
#define _USE_MATH_DEFINES
/* Definitions of useful mathematical constants
 * M_E        - e
 * M_LOG2E    - log2(e)
 * M_LOG10E   - log10(e)
 * M_LN2      - ln(2)
 * M_LN10     - ln(10)
 * M_PI       - pi
 * M_PI_2     - pi/2
 * M_PI_4     - pi/4
 * M_1_PI     - 1/pi
 * M_2_PI     - 2/pi
 * M_2_SQRTPI - 2/sqrt(pi)
 * M_SQRT2    - sqrt(2)
 * M_SQRT1_2  - 1/sqrt(2)
 */

#endif /* calculator_hpp */
void calculator(TgBot::Bot& bot, TgBot::Message::Ptr message);
void calculatorEngine(TgBot::Bot& bot, TgBot::Message::Ptr message);
void exitcalculator(TgBot::Bot& bot, TgBot::Message::Ptr message);
// generate
void onClickButton0(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton1(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton2(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton3(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickButton4(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
// exit
void onClickbuttonexit(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
void onClickbuttoncont(TgBot::Bot& bot, TgBot::CallbackQuery::Ptr query);
// functions
// разделение сообщение от пользователя на элементы строк в vector
// для 0
std::vector<std::string> splitstr0(const std::string& str);
// для 1
std::vector<std::string> splitstr1(std::string& str);
//----------------------------------------------------------------
long double func0(const long double& num1,
                  const long double& num2, std::string& operation);
long double func1(const long double& num1,
                  const long double& num2, std::string& operation);
long double func2(const long double& num1, std::string& operation);
long double func3(const long double& num1, std::string& operation);
