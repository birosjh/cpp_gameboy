#include <string>
#include <cstdint>

namespace General {
    // General Operation Functions
    uint16_t NOP();
    uint16_t STOP();
    uint16_t HALT();
    // Jump Operation Functions

    uint16_t JR();
    uint16_t JP();
}