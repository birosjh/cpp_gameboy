#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include <unordered_map>

enum Flag {
    Zero, Negative, HalfCarry, Carry
};

enum FlagState {
    ZeroOff, ZeroOn, CarryOff, CarryOn // my wayward son
};

enum Register {
    A, B, C, D, E, H, L, F
};

enum DoubleRegister {
    BC, DE, HL, SP, PC
};


class CPU {
    private:
        uint16_t stack_pointer;
        uint16_t program_counter;
        bool IME = false;

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
        void pc(uint8_t first, uint8_t second);

        uint16_t bc();
        void bc(uint16_t value);

        uint16_t de();
        void de(uint16_t value);

        uint16_t hl();
        void hl(uint16_t value);

        uint16_t sp();
        void sp(uint16_t value);

        uint8_t f();
        void f(uint8_t);

        void enable_ime();
        void disable_ime();


};

#endif // CPU_H