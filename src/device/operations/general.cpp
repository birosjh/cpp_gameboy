#include "general.h"

// -----------------------------------------------
// General Operation Functions
// -----------------------------------------------

uint16_t General::NOP() {
    return cpu.pc + 1;
}

uint16_t General::STOP() {
    // TODO: Make stop wait for button press
    return cpu.pc + 1;
}

uint16_t General::HALT() {
    // TODO: Make halt wait for button press
    return cpu.pc + 1;
}

// -----------------------------------------------
// Jump Operation Functions
// -----------------------------------------------

uint16_t Device::JR() {
    // TODO: Check implementation of JR
    // Def: Add n to current address and jump to it.
    return cpu.pc + 2;
}