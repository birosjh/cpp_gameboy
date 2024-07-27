#include <exception>

#include "load.h"

// -----------------------------------------------
// Load Commands
// -----------------------------------------------


uint16_t LD::single_from_single(CPU& cpu, Register in_register, Register load_register) {

    cpu.registers[in_register] = cpu.registers[load_register];

    return cpu.pc() + 1;
}


uint16_t LD::single_from_address(CPU& cpu, MemoryBus& memory_bus, Register in_register, uint16_t address) {


    auto value_at_address = memory_bus.read_from_memory(address);

    cpu.registers[in_register] = value_at_address;

    return cpu.pc() + 1;
}

uint16_t LD::single_from_value(CPU& cpu, Register in_register, uint8_t value) {

    cpu.registers[in_register] = value;

    return cpu.pc() + 1;
}

uint16_t LD::to_address_from_single(CPU& cpu, MemoryBus& memory_bus, uint16_t address, Register load_register) {

    auto value = cpu.registers[load_register];

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t LD::double_from_value(CPU& cpu, DoubleRegister in_register, uint16_t value) {

    cpu.double_register(in_register, value);

    return cpu.pc() + 1;
}
