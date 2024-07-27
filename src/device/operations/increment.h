#ifndef INCREMENT_H
#define INCREMENT_H

#include <string>
#include <cstdint>
#include <vector>

#include "cpu.h"
#include "memory_bus.h"

// Increment/Decrement Operation Functions

namespace INC {
    uint16_t single(CPU& cpu, Register in_register);
    uint16_t pair(CPU& cpu, DoubleRegister double_register);
    uint16_t address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister double_register);
}

namespace DEC {
    uint16_t single(CPU& cpu, Register in_register);
    uint16_t pair(CPU& cpu, DoubleRegister double_register);
    uint16_t address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister double_register);
}

#endif // INCREMENT_H