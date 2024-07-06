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