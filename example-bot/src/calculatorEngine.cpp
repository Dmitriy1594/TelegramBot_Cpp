#include "api.hpp"
#include "utils.hpp"
#include "keyboard.hpp"
// calculator
#include "keyboard.hpp"
#include "calculator.hpp"
//
using namespace std;
using namespace TgBot;
using namespace Utils;
//
// глобальные флаги
// calculator
extern int WAITING_MESSAGE;

void calculatorEngine(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    // Calculator
    long double num1 = 0;
    long double num2 = 0;
    std::string operation = "";
    //
    switch (WAITING_MESSAGE) {
        case 0: {
            printf("User wrote %s\n", message->text.c_str());
            std::string sentance = {};
            sentance = message->text.c_str();
            //
            std::vector<std::string> strs = splitstr0(sentance);
            //
            if (strs.size() == 1) {
                bot.getApi().sendMessage(message->chat->id,
                                         Utils::fromLocale("Калькулятор обнаружил ошибку! Ожидайте перезапуск."));
                num1 = 0;
                num2 = 0;
                operation = "";
                sentance = {};
                WAITING_MESSAGE = -3;
                calculator(bot, message);
                return;
            }
            //
            num1 = std::stold(strs[0]);
            operation = strs[1];
            num2 = std::stold(strs[2]);
            //
            bot.getApi().sendMessage(message->chat->id, (message->from->username + message->text.c_str() +
                                                         + " = " + to_string(func0(num1, num2, operation))));
            break;
        }
            //
        case 1: {
            printf("User wrote %s\n", message->text.c_str());
            std::string sentance = {};
            sentance = message->text.c_str();
            //
            std::vector<std::string> strs = splitstr1(sentance);
            //
            if (strs.size() == 1) {
                bot.getApi().sendMessage(message->chat->id,
                                         Utils::fromLocale("Калькулятор обнаружил ошибку! Ожидайте перезапуск."));
                num1 = 0;
                num2 = 0;
                operation = "";
                sentance = {};
                WAITING_MESSAGE = -3;
                calculator(bot, message);
                return;
            }
            //
            operation = strs[0];
            if (operation == "log") {
                num1 = std::stold(strs[1]);
                num2 = std::stold(strs[2]);
                bot.getApi().sendMessage(message->chat->id, (message->from->username + message->text.c_str() +
                                                             + " = " + to_string(func1(num1, num2, operation))));
            } else if (operation != "log") {
                num1 = std::stold(strs[1]);
                bot.getApi().sendMessage(message->chat->id, (message->from->username + message->text.c_str() +
                                                             + " = " + to_string(func1(num1, num2, operation))));
            } else {
                bot.getApi().sendMessage(message->chat->id,
                                         Utils::fromLocale("Калькулятор обнаружил ошибку! Ожидайте перезапуск."));
                num1 = 0;
                num2 = 0;
                operation = "";
                sentance = {};
                WAITING_MESSAGE = -3;
                calculator(bot, message);
                return;
            }
            break;
        }
            //
        case 2: {
            printf("User wrote %s\n", message->text.c_str());
            std::string sentance = {};
            sentance = message->text.c_str();
            //
            std::vector<std::string> strs = splitstr1(sentance);
            //
            if (strs.size() == 1) {
                bot.getApi().sendMessage(message->chat->id,
                                         Utils::fromLocale("Калькулятор обнаружил ошибку! Ожидайте перезапуск."));
                num1 = 0;
                num2 = 0;
                operation = "";
                sentance = {};
                WAITING_MESSAGE = -3;
                calculator(bot, message);
                return;
                break;
            }
            //
            operation = strs[0];
            num1 = std::stold(strs[1]);
            bot.getApi().sendMessage(message->chat->id, (message->from->username + operation + " " + to_string(num1 * M_PI)
                                                         + " = " + to_string(func2((num1 * M_PI), operation))));
            break;
        }
            //
        case 3: {
            printf("User wrote %s\n", message->text.c_str());
            std::string sentance = {};
            sentance = message->text.c_str();
            //
            std::vector<std::string> strs = splitstr1(sentance);
            //
            if (strs.size() == 1) {
                bot.getApi().sendMessage(message->chat->id,
                                         Utils::fromLocale("Калькулятор обнаружил ошибку! Ожидайте перезапуск."));
                num1 = 0;
                num2 = 0;
                operation = "";
                sentance = {};
                WAITING_MESSAGE = -3;
                calculator(bot, message);
                return;
            }
            //
            operation = strs[0];
            num1 = std::stold(strs[1]);
            bot.getApi().sendMessage(message->chat->id, (message->from->username + message->text.c_str()
                                                         + " = " + to_string(func3(num1, operation)) + " рад = " + to_string((func3(num1, operation)*180)/M_PI) + "°"));
            break;
        }
            //
        default: {
            num1 = 0;
            num2 = 0;
            operation = "";
            WAITING_MESSAGE = -9;
            return;
        }
    }
    num1 = 0;
    num2 = 0;
    operation = "";
    WAITING_MESSAGE = -3;
    exitcalculator(bot, message);
    return;
}
