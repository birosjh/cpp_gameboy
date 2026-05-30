#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class Cartridge {

    public:
        std::vector<char> game;

        Cartridge();

    private:

        std::vector<fs::path> find_games();
        bool is_valid_game_directory(fs::path games_path);
        bool is_valid_game(fs::directory_entry game_entry);
    
};

#endif  // CARTRIDGE_H