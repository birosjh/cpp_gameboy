#ifndef JUMP_H
#define JUMP_H

#include <string>
#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

// Jump Operation Functions

enum Vector {
    x00, x08, x10, x18, x20, x28, x30, x38
};

extern std::unordered_map<Vector, uint16_t> vector_values;

namespace JP {
    uint16_t to_address(CPU& cpu, uint16_t address);
    uint16_t to_address_from_value(CPU& cpu, MemoryBus& memory_bus);
    uint16_t to_address_in_register(CPU& cpu, DoubleRegister in_register);
    uint16_t to_address_from_value_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state);
}

namespace JR {
    uint16_t by_adding(CPU& cpu, MemoryBus& memory_bus);
    uint16_t by_adding_if_flag(CPU& cpu, MemoryBus& memory_bus, Flag flag);
    uint16_t by_adding_if_not_flag(CPU& cpu, MemoryBus& memory_bus, Flag flag);
}

namespace CALL {

    uint16_t address_from_value(CPU& cpu, MemoryBus& memory_bus);
    uint16_t address_from_value_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state);

}

namespace RST {
    uint16_t vector(CPU& cpu, MemoryBus& memory_bus, Vector vector);
}

#endif // JUMP_H
