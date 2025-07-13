#ifndef COPY_H
#define COPY_H

#include "cpu.h"
#include "memory_bus.h"

namespace CP {
    uint16_t to_register(CPU& cpu, Register compare_register);
    uint16_t to_address_value(CPU& cpu, MemoryBus& memory_bus, uint16_t address);
    uint16_t to_next_in_memory(CPU& cpu, MemoryBus& memory_bus);
    uint16_t to_value(CPU& cpu, uint8_t value);
}

#endif // COPY_H