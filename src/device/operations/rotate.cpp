#include "rotate.h"

// -----------------------------------------------
// Rotate Commands
// -----------------------------------------------


uint16_t Rotate::RLC(CPU& cpu, Register in_register) {
    auto register_value = cpu.registers[in_register];
    // TODO: Set Carry flag with left most bit
    register_value = (1 << register_value)|(1 >> (8 - register_value));

    return cpu.pc() + 1;
}

uint16_t Rotate::RL(CPU& cpu, Register in_register) {
    auto register_value = cpu.registers[in_register];
    // TODO: Check definition of RL
    // register_value = (1 << register_value)|(1 >> (8 - register_value));

    return cpu.pc() + 1;
}

uint16_t Rotate::RRC(CPU& cpu, Register in_register) {
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
