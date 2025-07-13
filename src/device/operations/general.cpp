#include "general.h"

// -----------------------------------------------
// General Operation Functions
// -----------------------------------------------

uint16_t NOP::run(CPU& cpu) {
    return cpu.pc() + 1;
}

uint16_t STOP::run(CPU& cpu) {
    // TODO: Make stop wait for button press
    return cpu.pc() + 1;
}

uint16_t HALT::run(CPU& cpu) {
    // TODO: Make halt wait for button press
    return cpu.pc() + 1;
}

uint16_t SCF::run(CPU& cpu) {
    cpu.flags[Carry] = true;

    return cpu.pc() + 1;
}

uint16_t CCF::run(CPU& cpu) {
    cpu.flags[Carry] = !cpu.flags[Carry];

    return cpu.pc() + 1;
}

uint16_t CPL::run(CPU& cpu) {
    cpu.registers[A] = ~cpu.registers[A];

    cpu.flags[Negative] = true;
    cpu.flags[HalfCarry] = true;

    return cpu.pc() + 1;
}

uint16_t DAA::run(CPU& cpu) {
    uint8_t correction = 0;
    bool set_carry = false;

    if(cpu.flags[Negative]) {
        if (cpu.flags[HalfCarry] || (cpu.registers[A] & 0x0F) > 9) {
            correction += 0x06;
        }
        if (cpu.flags[Carry] || cpu.registers[A] > 0x99) {
            correction += 0x60;
            set_carry = true;
        }
        cpu.registers[A] += correction;

    } else {
        if (cpu.flags[HalfCarry]) {
            correction += 0x06;
        }
        if (cpu.flags[Carry]) {
            correction += 0x60;
            set_carry = true;
        }
        cpu.registers[A] -= correction;
    }

    cpu.flags[Zero] = cpu.registers[A] == 0;
    cpu.flags[HalfCarry] = false;
    cpu.flags[Carry] = set_carry;

    return cpu.pc() + 1;
}

uint16_t EI::run(CPU& cpu) {

    cpu.enable_ime();

    return cpu.pc() + 1;
}

uint16_t DI::run(CPU& cpu) {

    cpu.enable_ime();

    return cpu.pc() + 1;
}