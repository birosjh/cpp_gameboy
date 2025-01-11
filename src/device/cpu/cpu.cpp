#include <bitset>

#include "cpu.h"
// -----------------------------------------------
// Flag Register Logic
// -----------------------------------------------

uint8_t CPU::f() {
    typedef std::size_t position_t;

    std::bitset<8> flag_bits;
    flag_bits.set(position_t(7), flags[Zero]);
    flag_bits.set(position_t(6), flags[Negative]);
    flag_bits.set(position_t(5), flags[HalfCarry]);
    flag_bits.set(position_t(4), flags[Carry]);

    uint8_t flag_register = static_cast<uint8_t>(flag_bits.to_ulong());

    return flag_register;
}

void CPU::f(uint8_t value) {
    std::bitset<8> flag_bits(value);
    flags[Zero] = flag_bits[7];
    flags[Negative] = flag_bits[6];
    flags[HalfCarry] = flag_bits[5];
    flags[Carry] = flag_bits[4];
}

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

void CPU::pc(uint8_t first, uint8_t second) {
    program_counter = ((uint16_t)second << 8) | first;
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