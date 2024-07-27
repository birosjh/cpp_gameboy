#ifndef JUMP_H
#define JUMP_H

#include <string>
#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

// Jump Operation Functions

namespace JP {
    uint16_t to_address(CPU& cpu, uint16_t address);
    uint16_t to_address_in_register(CPU& cpu, std::string in_register);
    uint16_t to_address_if_flag(CPU& cpu, std::string flag, uint16_t address);
}

#endif // JUMP_H
