#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

// Load Operation Functions

enum Modifier {
    Inc, Dec
};

namespace LD {
    uint16_t single_from_single(CPU& cpu, Register in_register, Register load_register);
    uint16_t single_from_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, DoubleRegister address_register);
    uint16_t single_from_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, DoubleRegister address_register, Modifier modifier);
    uint16_t single_from_value(CPU& cpu, Register Register, uint8_t value);
    uint16_t to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register);
    uint16_t to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register, Modifier modifier);
    uint16_t to_address_from_value(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, uint8_t value);

    uint16_t double_from_value(CPU& cpu, DoubleRegister in_register, uint16_t value);
}

#endif // LOAD_H

        