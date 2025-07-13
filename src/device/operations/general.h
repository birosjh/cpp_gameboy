#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include <cstdint>

#include "cpu.h"
#include "memory_bus.h"

namespace NOP {
    // General Operation Functions
    uint16_t run(CPU& cpu);
}

namespace STOP {
    uint16_t run(CPU& cpu);
}

namespace HALT {
    uint16_t run(CPU& cpu);
}

namespace SCF {
    uint16_t run(CPU& cpu);
}

namespace CPL {
    uint16_t run(CPU& cpu);
}

namespace DAA {
    uint16_t run(CPU& cpu);
}

namespace CCF {
    uint16_t run(CPU& cpu);
}

namespace DI {
    uint16_t run(CPU& cpu);
}

namespace EI {
    uint16_t run(CPU& cpu);
}

#endif // GENERAL_H