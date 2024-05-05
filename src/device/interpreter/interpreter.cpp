#include <sstream>

#include "interpreter.h"


uint8_t Interpreter::read_next(uint16_t program_counter, Cartridge cartridge) {

    auto code = cartridge[program_counter];
    
    std::stringstream stream;

    auto value = static_cast<std::uint8_t>(code);
    stream << std::hex << static_cast<int>(value) << std::endl;

    std::string command = stream.str();

    return value;

    std::cout << command << std::endl;
}

std::string Interpreter::to_hex(const int code) {

}