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

    while(true) {

        // Get next opcode
        code = memory_bus.get_next_in_memory(cpu);
        // Execute opcode
        auto new_location = execute(code);
    }
}

uint16_t Device::execute(const int code) {

    return handle_operation(cpu, memory_bus, code);

}