#include <string>
#include <cstdint>

namespace Rotate {
    // Rotate Operation Functions
    uint16_t RLC(std::string in_register);
    uint16_t RL(std::string in_register);
    uint16_t RRC(std::string in_register);
    uint16_t RR(std::string in_register);
}