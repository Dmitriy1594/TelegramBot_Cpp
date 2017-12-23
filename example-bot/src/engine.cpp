#include "api.hpp"
#include "utils.hpp"
//
#include "keyboard.hpp"
#include "calculator.hpp"
#include "library.hpp"
#include "math.hpp"
#include "Al.hpp"
#include "En.hpp"
//
using namespace std;
using namespace TgBot;
using namespace Utils;
//
// глобальные флаги
// calculator
int WAITING_MESSAGE = -9;

// Функция для демонстрации работы с командами
// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /start
void onCommandCom(Bot& bot, Message::Ptr message);
void onCommandStart(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Hi!");
    onCommandCom(bot, message);
}
// Функция для демонстрации работы с командами
// Функция вызывается каждый раз, когда приходит сообщение, которое начинается со /end
void onCommandEnd(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Bye!");
}
// Функция для вывода всех команд, которые умеет выполнять бот
void onCommandCom(Bot& bot, Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("Вот команды, которые умею выполнять:"));
    std::map<std::string, std::string> commands = {
        {"/start", Utils::fromLocale(" == Начало")},
        {"/end", Utils::fromLocale(" == Конец")},
        {"/help", Utils::fromLocale(" == Вызов помощника студента")},
        {"/keyboard", Utils::fromLocale(" == Вызов помощника студента")},
        {"/allcommands", Utils::fromLocale(" == Вывод всех команд")},
        {"/commands", Utils::fromLocale(" == Вывод всех команд")}
    };
    std::string answs = {};
    for (auto it = commands.begin(); it != commands.end(); ++it)
    {
        answs += Utils::fromLocale((it->first) + " " + (it->second) + "\n");
    }
    bot.getApi().sendMessage(message->chat->id, answs);
}
// регистрируем команды
std::map<std::string, std::function<void(Bot&, Message::Ptr)>> getAllCommands()
{
    // Ключом является идентификатор команды
    // значением является функция-обработчик коаманды
    // Например, при получении команды /end вызовется функция onCommandEnd
    std::map<std::string, std::function<void(Bot&, Message::Ptr)>> commands =
    {
        {"start", onCommandStart},
        {"end", onCommandEnd},
        {"help", onCommandKeyboard},
        {"keyboard", onCommandKeyboard},
        {"allcommands", onCommandCom},
        {"commands", onCommandCom}
    };
    return commands;
}


// Функция, которая вызывается при любом сообщении
void onAnyMessage(Bot& bot, Message::Ptr message) {
    // логгируем действия в консоль
    printf("User wrote %s\n", message->text.c_str());
    //
    // игнорируем сообщения, которые начинаются с /start и /end и пр.
    if (StringTools::startsWith(message->text, "/start")) {
        return;
    }
    //
    if ((StringTools::startsWith(message->text, "/commands")) || (StringTools::startsWith(message->text, "/allcommands"))) {
        return;
    }
    //
    if ((StringTools::startsWith(message->text, "/help")) || (StringTools::startsWith(message->text, "/keyboard"))) {
        return;
    }
    //
    if (StringTools::startsWith(message->text, "/end")) {
        return;
    }
    // Calculator
    calculatorEngine(bot, message);
    //
    // если в тексте сообщения есть "Привет" или "hi" или "Hi!" или "Hi", то приветствуем собеседника
    if (StringTools::startsWith(message->text, "hi")) {
        bot.getApi().sendMessage(message->chat->id, "hi, " + message->from->firstName);
        onCommandCom(bot, message);
        return;
    } else if ((StringTools::startsWith(message->text, "Hi!")) || (StringTools::startsWith(message->text, "Hi"))) {
        bot.getApi().sendMessage(message->chat->id, "Hi, " + message->from->firstName);
        onCommandCom(bot, message);
        return;
    }
    std::string hello = Utils::fromLocale("Привет");
    std::string hello1 = Utils::fromLocale("Привет!");
    if ((message->text.find(hello) != std::string::npos) || (message->text.find(hello1) != std::string::npos)) {
        bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("Привет, ") + message->from->firstName);
        onCommandCom(bot, message);
        return;
    }
    // отправляем сообщение об ошибке
    std::string answer = Utils::fromLocale("Такой команды нет, введите /allcommands или /commands, чтобы посмотреть все команды!");
}
