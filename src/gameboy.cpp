#include <string>

#include "cartridge.h"
#include "gameboy.h"

int main() {

    std::string game_file = "games/pokemon_yellow_jp.gb"
    
    Cartridge cartridge(game_file);

    Gameboy gameboy(cartridge);

    gameboy.play()

}