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
    uint16_t single_from_value(CPU& cpu, MemoryBus& memory_bus, Register in_register);
    uint16_t to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register);
    uint16_t to_address_from_single(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register, Register load_register, Modifier modifier);
    uint16_t to_address_from_single(CPU& cpu, MemoryBus& memory_bus, Register load_register);
    uint16_t to_address_from_value(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register);

    uint16_t double_from_value(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register);
    uint16_t double_from_double(CPU& cpu, DoubleRegister in_register, DoubleRegister from_register);
    uint16_t double_from_double(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register, DoubleRegister from_register);
}

namespace LDIO {
    uint16_t to_io_single_from_single(CPU& cpu, MemoryBus& memory_bus, Register io_register, Register value_register);
    uint16_t to_io_address_from_single(CPU& cpu, MemoryBus& memory_bus, Register value_register);
    uint16_t to_single_from_io_address(CPU& cpu, MemoryBus& memory_bus, Register in_register);
    uint16_t to_single_from_io_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, Register io_register);
}

#endif // LOAD_H

        