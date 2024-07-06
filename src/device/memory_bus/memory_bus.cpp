#include "memory_bus.h"


MemoryBus::MemoryBus() {

    rom.reserve(32767);

    // Load Boot Rom
    std::ifstream boot_rom("boot/dmg_boot.bin", std::ifstream::in);
    rom.insert(rom.begin(),
               std::istream_iterator<char>(boot_rom),
               std::istream_iterator<char>());

}

uint8_t MemoryBus::read_from_memory(uint16_t location) {
    return rom[location];
}

void MemoryBus::write_to_memory(uint16_t location, uint8_t value) {
    rom[location] = value;
}