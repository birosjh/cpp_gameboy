#ifndef BOOL_H
#define BOOL_H

#include "cpu.h"
#include "memory_bus.h"

namespace AND {
    uint16_t with_register(CPU& cpu, Register compare_register);
    uint16_t with_address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register);
    uint16_t with_value(CPU& cpu, uint8_t value);
}

namespace OR {
    uint16_t with_register(CPU& cpu, Register compare_register);
    uint16_t with_address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register);
    uint16_t with_value(CPU& cpu, uint8_t value);
}

namespace XOR {
    uint16_t with_register(CPU& cpu, Register compare_register);
    uint16_t with_address(CPU& cpu, MemoryBus& memory_bus, DoubleRegister address_register);
    uint16_t with_value(CPU& cpu, uint8_t value);
}

#endif // BOOL_H