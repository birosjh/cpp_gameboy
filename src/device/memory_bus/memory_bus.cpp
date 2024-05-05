#include <sstream>

#include "interpreter.h"


uint8_t MemoryBus::read_next(uint16_t program_counter) {

    auto code = cartridge[program_counter];
    
    std::stringstream stream;

    auto value = static_cast<std::uint8_t>(code);
    stream << std::hex << static_cast<int>(value) << std::endl;

    std::string command = stream.str();

    return value;

    std::cout << command << std::endl;
}