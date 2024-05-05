#include <string>

#include "cartridge.h"
#include "device.h"

int main() {

    std::string game_file = "games/pokemon_yellow_jp.gb"
    
    Cartridge cartridge(game_file);

    Device gameboy();

    gameboy.play(cartridge)

}