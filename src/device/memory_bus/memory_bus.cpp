#include <sstream>

#include "memory_bus.h"


MemoryBus::MemoryBus() {
    // Load Boot Rom
    std::ifstream boot_rom("boot/dmg_boot.bin", std::ifstream::in);
    boot_rom.read(&rom[0], 256);
}

uint8_t MemoryBus::read_from_memory(uint16_t location) {
    return rom[location];
}

void MemoryBus::write_to_memory(uint16_t location, uint8_t value) {
    rom[location] = value;
}