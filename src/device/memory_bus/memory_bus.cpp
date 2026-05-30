#include "memory_bus.h"


MemoryBus::MemoryBus() {

    rom.reserve(65536);

    // Load Boot Rom
    std::ifstream boot_rom("boot/dmg_boot.bin", std::ios::in | std::ios::binary);
    rom.insert(
        rom.begin(),
        std::istreambuf_iterator<char>(boot_rom),
        std::istreambuf_iterator<char>()
    );

}

uint8_t MemoryBus::read_from_memory(uint16_t location) {
    return rom[location];
}

uint8_t MemoryBus::get_next_in_memory(CPU& cpu) {
    auto value = read_from_memory(cpu.pc());

    // Move to next 
    cpu.pc(cpu.pc() + 1);

    return value;
}

void MemoryBus::write_to_memory(uint16_t location, uint8_t value) {
    std::cout << location << std::endl;
    rom[location] = value;
}