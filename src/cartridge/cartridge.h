#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <string>
#include <vector>
#include <fstream>

class Cartridge {

    public:
        std::vector<char> game;

        Cartridge(std::string game_file);
    
};

#endif  // CARTRIDGE_H