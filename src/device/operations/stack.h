#ifndef STACK_H
#define STACK_H

#include "cpu.h"
#include "memory_bus.h"
#include "general.h"

namespace POP {
    uint16_t register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second);
}

namespace PUSH {
    uint16_t register_pair(CPU& cpu, MemoryBus& memory_bus, Register first, Register second);
}

namespace RET {

    int16_t run(CPU& cpu, MemoryBus& memory_bus);
    int16_t run(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state);

}

namespace RETI {
    int16_t run(CPU& cpu, MemoryBus& memory_bus);
}

#endif // STACK_H