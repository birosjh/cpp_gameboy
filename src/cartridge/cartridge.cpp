#include "cartridge.h"

Cartridge::Cartridge(std::string game_file) {

    std::ifstream game_data(game_file, std::ifstream::in);

    game_data.seekg(0, game_data.end);
    int length = game_data.tellg();
    game_data.seekg(0, game_data.beg);

    game.resize(length);

    game_data.read(&game[0], length);
    game_data.close();
}