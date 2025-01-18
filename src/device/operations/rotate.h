#ifndef ROTATE_H
#define ROTATE_H

#include "cpu.h"
#include "memory_bus.h"

namespace Rotate {
    // Rotate Operation Functions
    uint16_t RL(CPU& cpu, Register in_register);
    uint16_t RRC(CPU& cpu, Register in_register);
    uint16_t RR(CPU& cpu, Register in_register);
}

namespace RLC {
    uint16_t run(CPU& cpu, Register in_register);
    uint16_t run(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register);
}

namespace RRC {
    uint16_t run(CPU& cpu, Register in_register);
}

#endif // ROTATE_H