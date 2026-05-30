#include "device.h"
#include "logger.h"

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

    Log::counter(cpu);

    code = memory_bus.get_next_in_memory(cpu);

    while(code) {

        Log::code(code);

        // Execute opcode
        auto new_location = execute(code);

        Log::counter(cpu);

        // Get next opcode
        code = memory_bus.get_next_in_memory(cpu);
    }
}

uint16_t Device::execute(const int code) {

    return handle_operation(cpu, memory_bus, code);

}