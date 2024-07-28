#ifndef JUMP_H
#define JUMP_H

#include <string>
#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

// Jump Operation Functions

namespace JP {
    uint16_t to_address(CPU& cpu, uint16_t address);
    uint16_t to_address_in_register(CPU& cpu, DoubleRegister in_register);
    uint16_t to_address_if_flag(CPU& cpu, Flag flag, uint16_t address);
}

namespace JR {
    uint16_t by_adding(CPU& cpu, uint8_t value);
    uint16_t by_adding_if_flag(CPU& cpu, Flag flag, uint8_t value);
}

#endif // JUMP_H
