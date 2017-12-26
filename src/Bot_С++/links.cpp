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
#include "links.hpp"

std::vector<std::string> loadFromFileLinks(const std::string& filename) {
    std::vector<std::string> consts = {};
    std::fstream fl(filename, std::ios_base::in);
    std::string str = "";
    while (!fl.eof()) {
        std::getline(fl, str);
        consts.push_back(str);
        str = {};
    }
    return consts;
}

void links(TgBot::Bot& bot, TgBot::Message::Ptr message) {
    // файл с константами
    const std::string filename = "links.txt";
    std::vector<std::string> consts = loadFromFileLinks(filename);
    std::string answer1 = {};
    for (auto con : consts) {
        answer1 += (con + "\n");
    }
    bot.getApi().sendMessage(message->chat->id, answer1);
    // exit
    exitlibrary(bot, message);
}
