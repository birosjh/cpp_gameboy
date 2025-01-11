#ifndef CALL_H
#define CALL_H

#include "cpu.h"
#include "memory_bus.h"

namespace CALL {

    uint16_t address(CPU& cpu, MemoryBus& memory_bus, uint16_t value);
    uint16_t address_if_flag_state(CPU& cpu, MemoryBus& memory_bus, FlagState flag_state, uint16_t value);

}

#endif // CALL_H