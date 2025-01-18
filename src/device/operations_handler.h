#ifndef OPERATIONS_HANDLER_H
#define OPERATIONS_HANDLER_H

#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"


uint16_t handle_operation(CPU& cpu, MemoryBus& memory_bus, uint8_t command);
void handle_prefixed_operation(CPU& cpu, MemoryBus& memory_bus, uint8_t command);

#endif // OPERATIONS_HANDLER_H