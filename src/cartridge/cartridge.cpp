#include "cartridge.h"

Cartridge::Cartridge() {

    std::vector<fs::path> games = find_games();

    int choice;

    std::cout << "Select a game by number: ";
    std::cin >> choice;

    fs::path game_file = games[choice];

    std::ifstream game_data(game_file, std::ifstream::in);

    game_data.seekg(0, game_data.end);
    int length = game_data.tellg();
    game_data.seekg(0, game_data.beg);

    game.resize(length);

    game_data.read(&game[0], length);
    game_data.close();
    
}

std::vector<fs::path> Cartridge::find_games() {

    fs::path games_path = "/code/games";

    std::vector<fs::path> games;

    try {
        if (is_valid_game_directory(games_path)) {
            for (const auto& entry : fs::directory_iterator(games_path)) {
                if (is_valid_game(entry)) {
                    std::cout << entry.path().filename() << std::endl;
                    games.push_back(entry.path());
                }
            }
        }

    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    if (games.size() < 1) {
        std::cerr << "Error: No games found" << '\n';
    }

    return games;
}

bool Cartridge::is_valid_game_directory(fs::path games_path) {
    return fs::exists(games_path) && fs::is_directory(games_path);
}

bool Cartridge::is_valid_game(fs::directory_entry game_entry) {
    return fs::is_regular_file(game_entry.status()) && game_entry.path().extension().string() == ".gb";
}