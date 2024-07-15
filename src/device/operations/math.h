#ifndef MATH_H
#define MATH_H

#include <string>

#include "cpu.h"
#include "memory_bus.h"

namespace ADD {
    uint16_t single_registers(CPU& cpu, std::string in_register, std::string add_register);
    uint16_t double_registers(CPU& cpu, std::string in_register, std::string add_register);
    uint16_t to_single_using_address(CPU& cpu, MemoryBus& memory_bus, std::string in_register, uint16_t address);
}

namespace SUB {
    uint16_t single_registers(CPU& cpu, std::string in_register, std::string add_register);
    uint16_t double_registers(CPU& cpu, std::string in_register, std::string add_register);
    uint16_t from_single_using_address(CPU& cpu, MemoryBus& memory_bus, std::string in_register, uint16_t address);
}

#endif // MATH_H