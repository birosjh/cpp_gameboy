#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include <unordered_map>

enum Flag {
    Zero, Negative, HalfCarry, Carry
};

enum Register {
    A, B, C, D, E, H, L
};

enum DoubleRegister {
    BC, DE, HL, SP, PC
};


class CPU {
    private:
        uint16_t stack_pointer;
        uint16_t program_counter;

    public:

        std::unordered_map<Register, uint8_t> registers =
        {
            {A, 0},
            {B, 0},
            {C, 0},
            {D, 0},
            {E, 0},
            {H, 0},
            {L, 0},
        };

        std::unordered_map<Flag, bool> flags =
        {
            {Zero, false},
            {Negative, false},
            {HalfCarry, false},
            {Carry, false},
        };

        uint16_t double_register(DoubleRegister register_name);
        void double_register(DoubleRegister register_name, uint16_t value);
        
        uint16_t pc();
        void pc(uint16_t value);

        uint16_t bc();
        void bc(uint16_t value);

        uint16_t de();
        void de(uint16_t value);

        uint16_t hl();
        void hl(uint16_t value);

        uint16_t sp();
        void sp(uint16_t value);

};

#endif // CPU_H