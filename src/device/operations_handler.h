#ifndef OPERATIONS_HANDLER_H
#define OPERATIONS_HANDLER_H

#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"
#include "operations/bool.h"
#include "operations/compare.h"
#include "operations/general.h"
#include "operations/increment.h"
#include "operations/jump.h"
#include "operations/math.h"
#include "operations/rotate.h"
#include "operations/stack.h"
#include "operations/load.h"
#include "operations/compare.h"

uint16_t handle_operation(CPU& cpu, MemoryBus& memory_bus, uint8_t command);
uint16_t handle_prefixed_operation(CPU& cpu, MemoryBus& memory_bus);

#endif // OPERATIONS_HANDLER_H