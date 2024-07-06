#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

// Load Operation Functions

namespace LD {
    uint16_t single_from_single(CPU& cpu, std::string in_register, std::string load_register);
    uint16_t single_from_address(CPU& cpu, MemoryBus& memory_bus, std::string in_register, uint16_t address);
    uint16_t single_from_value(CPU& cpu, std::string in_register, uint8_t value);
    uint16_t address_from_single(CPU& cpu, MemoryBus& memory_bus, uint16_t address, std::string load_register);

    uint16_t double_from_value(CPU& cpu, std::string in_register, uint16_t value);
}

#endif // LOAD_H

        