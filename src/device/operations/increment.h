#include <string>
#include <cstdint>
#include <vector>

#include "cpu.h"
#include "memory_bus.h"

// Increment/Decrement Operation Functions

namespace INC {
    uint16_t single(CPU& cpu, std::string in_register);
    uint16_t pair(CPU& cpu, std::string double_register);
    uint16_t address(CPU& cpu, MemoryBus& memory_bus, std::string double_register);
}

namespace DEC {
    uint16_t single(CPU& cpu, std::string in_register);
    uint16_t pair(CPU& cpu, std::string double_register);
    uint16_t address(CPU& cpu, MemoryBus& memory_bus, std::string double_register);
}