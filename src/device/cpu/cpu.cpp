#include "cpu.h"

// -----------------------------------------------
// 16 Bit Register Logic
// -----------------------------------------------

uint16_t CPU::bc() {
  return registers[B] | registers[C] << 8;
}

void CPU::bc(uint16_t value) {
    registers[B] = value & 0xFF;
    registers[C] = value >> 8;
}

uint16_t CPU::de() {
    return registers[D] | registers[E] << 8;
}

void CPU::de(uint16_t value) {
    registers[D] = value & 0xFF;
    registers[E] = value >> 8;
}

uint16_t CPU::hl() {
    return registers[H] | registers[L] << 8;
}

void CPU::hl(uint16_t value) {
    registers[H] = value & 0xFF;
    registers[L] = value >> 8;
}

uint16_t CPU::sp() {
    return stack_pointer;
}

void CPU::sp(uint16_t value) {
    stack_pointer = value;
}

uint16_t CPU::pc() {
    return program_counter;
}

void CPU::pc(uint16_t value) {
    program_counter = value;
}

uint16_t CPU::double_register(DoubleRegister register_name) {
    uint16_t value;

    if (register_name == BC) {
        value = bc();
    }
    else if (register_name == DE) {
        value = de();
    }
    else if (register_name == HL) {
        value = hl();
    }
    else if (register_name == SP) {
        value = sp();
    }

    return value;
}

void CPU::double_register(DoubleRegister register_name, uint16_t value) {
    if(register_name == BC) {
        bc(value);
    } else if(register_name == DE) {
        de(value);
    } else if(register_name == HL) {
        hl(value);
    } else if (register_name == SP) {
        sp(value);
    } else {
        throw "Register does not exist";
    }
}