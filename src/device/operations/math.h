#ifndef MATH_H
#define MATH_H

#include "cpu.h"
#include "memory_bus.h"

namespace ADD {
    uint16_t single_registers(CPU& cpu, Register in_register, Register add_register);
    uint16_t double_registers(CPU& cpu, DoubleRegister in_register, DoubleRegister add_register);
    uint16_t to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address);
    uint16_t value_to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register);
    uint16_t signed_integer(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register);
}

namespace ADC {
    uint16_t single_registers(CPU& cpu, Register in_register, Register add_register);
    uint16_t to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address);
    uint16_t value_to_single(CPU& cpu, MemoryBus& memory_bus, Register in_register);
}

namespace SUB {
    uint16_t single_registers(CPU& cpu, Register in_register, Register add_register);
    uint16_t from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address);
    uint16_t value_from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register);
}

namespace SBC {
    uint16_t single_registers(CPU& cpu, Register in_register, Register add_register);
    uint16_t from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address);
    uint16_t value_from_single(CPU& cpu, MemoryBus& memory_bus, Register in_register);
}

#endif // MATH_H