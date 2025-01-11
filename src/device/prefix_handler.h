#ifndef PREFIX_HANDLER_H
#define PREFIX_HANDLER_H

#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

namespace PREFIX_HANDLER {
    void handle(CPU& cpu, MemoryBus& memory_bus, uint8_t command);
}

#endif // PREFIX_HANDLER_H