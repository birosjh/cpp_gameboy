#ifndef STACK_H
#define STACK_H

#include "cpu.h"
#include "memory_bus.h"

namespace POP {
    uint16_t register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second);
}

namespace PUSH {
    uint16_t register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second);
}

#endif // STACK_H