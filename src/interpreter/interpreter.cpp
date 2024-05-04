#include <sstream>

#include "interpreter.h"


void Interpreter::interpret(const std::vector<char>& game) {

    for (auto code : game) {
        std::stringstream stream;

        auto value = static_cast<std::uint8_t>(code);
        stream << std::hex << static_cast<int>(value) << std::endl;

        std::string command = stream.str();

        lookup_command(value);

        std::cout << command << std::endl;
    }
}

void Interpreter::lookup_command(const int code) {

    switch(code) {
        case 0: // NOP
            std::cout << "NOP";
        case 1:
            
            
        case 2:


        default:
            // code block
    }

}

std::string Interpreter::to_hex(const int code) {

}