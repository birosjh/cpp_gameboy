#ifndef CALL_H
#define CALL_H

#include "cpu.h"
#include "memory_bus.h"
#include "jump.h"

enum Vector {
    x00, x08, x10, x18, x20, x28, x30, x38
};

std::unordered_map<Vector, uint16_t> vector_values {
    {x00, 0x0000},
    {x08, 0x0008},
    {x10, 0x0010},
    {x18, 0x0018},
    {x20, 0x0020},
    {x28, 0x0028},
    {x30, 0x0030},
    {x38, 0x0038}
};

namespace CALL {

    uint16_t address(CPU& cpu, MemoryBus& memory_bus, uint16_t value);
    uint16_t address_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state, uint16_t value);

}

namespace RST {
    uint16_t vector(CPU& cpu, MemoryBus& memory_bus, Vector vector);
}

#endif // CALL_H