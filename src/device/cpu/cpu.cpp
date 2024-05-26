#include "cpu.h"

// -----------------------------------------------
// 16 Bit Register Logic
// -----------------------------------------------

uint16_t CPU::bc() {
  return uint16_t(registers["b"]) << 8 | uint16_t(registers["c"]);
}

void CPU::bc(uint16_t value) {
    registers["b"] = uint8_t(value & 0xFF00 >> 8);
    registers["c"] = uint8_t(value & 0xFF);
}

uint16_t CPU::de() {
    return uint16_t(registers["d"]) << 8 | uint16_t(registers["e"]);
}

void CPU::de(uint16_t value) {
    registers["d"] = uint8_t(value & 0xFF00 >> 8);
    registers["e"] = uint8_t(value & 0xFF);
}

uint16_t CPU::hl() {
    return uint16_t(registers["h"]) << 8 | uint16_t(registers["l"]);
}

void CPU::hl(uint16_t value) {
    registers["h"] = uint8_t(value & 0xFF00 >> 8);
    registers["l"] = uint8_t(value & 0xFF);
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


// -----------------------------------------------
// Flag Logic
// -----------------------------------------------

void CPU::toggle_zero_flag() {
    registers["f"] ^= 1UL << zero_flag_position;
};
        
void CPU::toggle_subtract_flag() {
    registers["f"] ^= 1UL << subtract_flag_position;
};
        
void CPU::toggle_half_carry_flag() {
    registers["f"] ^= 1UL << half_carry_flag_position;
};
        
void CPU::toggle_carry_flag() {
    registers["f"] ^= 1UL << carry_flag_position;
};