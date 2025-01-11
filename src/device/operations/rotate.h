#include <string>
#include <cstdint>

namespace Rotate {
    // Rotate Operation Functions
    uint16_t RLC(CPU& cpu, Register in_register);
    uint16_t RL(CPU& cpu, Register in_register);
    uint16_t RRC(CPU& cpu, Register in_register);
    uint16_t RR(CPU& cpu, Register in_register);
}