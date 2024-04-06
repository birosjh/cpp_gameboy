#include "cpu.h"

// -----------------------------------------------
// 16 Bit Register Logic
// -----------------------------------------------

uint16_t Registers::get_bc() {
  return uint16_t(b) << 8 | uint16_t(c);
}

void Registers::set_bc(uint16_t value) {
    b = uint8_t(value & 0xFF00 >> 8);
    c = uint8_t(value & 0xFF);
}

uint16_t Registers::get_de() {
    return uint16_t(d) << 8 | uint16_t(e);
}

void Registers::set_de(uint16_t value) {
    d = uint8_t(value & 0xFF00 >> 8);
    e = uint8_t(value & 0xFF);
}

uint16_t Registers::get_hl() {
    return uint16_t(h) << 8 | uint16_t(l);
}

void Registers::set_hl(uint16_t value) {
    h = uint8_t(value & 0xFF00 >> 8);
    l = uint8_t(value & 0xFF);
}

// -----------------------------------------------
// Flag Logic
// -----------------------------------------------

void Registers::toggle_zero_flag() {
    f ^= 1UL << zero_flag_position;
};
        
void Registers::toggle_subtract_flag() {
    f ^= 1UL << subtract_flag_position;
};
        
void Registers::toggle_half_carry_flag() {
    f ^= 1UL << half_carry_flag_position;
};
        
void Registers::toggle_carry_flag() {
    f ^= 1UL << carry_flag_position;
};