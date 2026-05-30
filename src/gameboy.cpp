#include <string>
#include <iostream>

#include "cartridge.h"
#include "device.h"

int main() {
    
    Cartridge cartridge;

    std::cout << cartridge.game.size() << std::endl;

    Device gameboy(cartridge);

    gameboy.run();

}