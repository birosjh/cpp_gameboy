#include <string>
#include <cstdint>

namespace General {
    // General Operation Functions
    uint16_t NOP(CPU& cpu);
    uint16_t STOP(CPU& cpu);
    uint16_t HALT(CPU& cpu);
    // Jump Operation Functions

    uint16_t JR(CPU& cpu);
    uint16_t JP(CPU& cpu);
}