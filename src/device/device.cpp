#include <iomanip>
#include "device.h"

Device::Device(Cartridge cartridge) :
    current_game(cartridge),
    memory_bus(),
    cpu()
{
    // Set CPU Program Counter
    cpu.pc(0);
}

void Device::run() {
    uint8_t code;

    std::cout << "Program Counter: " << cpu.pc() << std::endl;

    code = memory_bus.get_next_in_memory(cpu);

    while(code) {

        std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(code) << std::endl;

        // Execute opcode
        auto new_location = execute(code);

        std::cout << "Program Counter: " << cpu.pc() << std::endl;

        // Get next opcode
        code = memory_bus.get_next_in_memory(cpu);
    }
}

uint16_t Device::execute(const int code) {

    return handle_operation(cpu, memory_bus, code);

}