#include "rotate.h"

// -----------------------------------------------
// Rotate Commands
// -----------------------------------------------


uint16_t RLC::run(CPU& cpu, Register in_register) {
    auto register_value = cpu.registers[in_register];
    // TODO: Set Carry flag with left most bit
    cpu.registers[in_register] = (1 << register_value)|(1 >> (8 - register_value));

    return cpu.pc() + 1;
}

uint16_t RLC::run(CPU& cpu, MemoryBus& memory_bus, DoubleRegister in_register) {
    auto address = cpu.double_register(in_register);
    auto value = memory_bus.read_from_memory(address);
    // TODO: Set Carry flag with left most bit
    value = (1 << value)|(1 >> (8 - value));

    memory_bus.write_to_memory(address, value);

    return cpu.pc() + 1;
}

uint16_t Rotate::RL(CPU& cpu, Register in_register) {
    auto register_value = cpu.registers[in_register];
    // TODO: Check definition of RL
    // register_value = (1 << register_value)|(1 >> (8 - register_value));

    return cpu.pc() + 1;
}

uint16_t RRC::run(CPU& cpu, Register in_register) {
    auto register_value = cpu.registers[in_register];
    // TODO: Check definition of RRC
    // register_value = (1 << register_value)|(1 >> (8 - register_value));

    return cpu.pc() + 1;
}

uint16_t Rotate::RR(CPU& cpu, Register in_register) {
    auto register_value = cpu.registers[in_register];
    // TODO: Check definition of RR
    // register_value = (1 << register_value)|(1 >> (8 - register_value));

    return cpu.pc() + 1;
}
