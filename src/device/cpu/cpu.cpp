#include "cpu.h"

// -----------------------------------------------
// 16 Bit Register Logic
// -----------------------------------------------

uint16_t CPU::bc() {
  return registers["b"] | registers["c"] << 8;
}

void CPU::bc(uint16_t value) {
    registers["b"] = value & 0xFF;
    registers["c"] = value >> 8;
}

uint16_t CPU::de() {
    return registers["d"] | registers["e"] << 8;
}

void CPU::de(uint16_t value) {
    registers["d"] = value & 0xFF;
    registers["e"] = value >> 8;
}

uint16_t CPU::hl() {
    return registers["h"] | registers["l"] << 8;
}

void CPU::hl(uint16_t value) {
    registers["h"] = value & 0xFF;
    registers["l"] = value >> 8;
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

uint16_t CPU::double_register(std::string register_name) {
    uint16_t value;

    if (register_name == "bc") {
        value = bc();
    }
    else if (register_name == "de") {
        value = de();
    }
    else if (register_name == "hl") {
        value = hl();
    }
    else if (register_name == "sp") {
        value = sp();
    }

    return value;
}

void CPU::double_register(std::string register_name, uint16_t value) {
    if(register_name == "bc") {
        bc(value);
    } else if(register_name == "de") {
        de(value);
    } else if(register_name == "hl") {
        hl(value);
    } else if (register_name == "sp") {
        sp(value);
    } else {
        throw "Register does not exist";
    }
}