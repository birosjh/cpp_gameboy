#include <string>
#include <iostream>

#include "cartridge.h"
#include "device.h"

int main() {

    std::string game_file = "games/dmg_boot.bin";
    
    Cartridge cartridge(game_file);

    std::cout << cartridge.game.size() << std::endl;

    Device gameboy(cartridge);

}