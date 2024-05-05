#include <fstream>
#include <string>
#include <vector>

#include "interpreter.h"

int main() {
    
    Interpreter interpreter;

    std::ifstream cartridge("games/pokemon_yellow_jp.gb", std::ifstream::in);

    cartridge.seekg(0, cartridge.end);
    int length = cartridge.tellg();
    cartridge.seekg(0, cartridge.beg);

    std::vector<char> game(length);

    cartridge.read(&game[0], length);
    cartridge.close();

    interpreter.interpret(game);

}