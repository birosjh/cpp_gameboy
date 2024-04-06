#ifndef CPU_H
#define CPU_H

#include <cstdint>

class Registers {
    private:
        static const uint8_t zero_flag_position = 7;
        static const uint8_t subtract_flag_position = 6;
        static const uint8_t half_carry_flag_position = 5;
        static const uint8_t carry_flag_position = 4;

    public:
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t f;
        uint8_t h;
        uint8_t l;

        uint16_t get_bc();
        void set_bc(uint16_t value);

        uint16_t get_de();
        void set_de(uint16_t value);

        uint16_t get_hl();
        void set_hl(uint16_t value);

        void toggle_zero_flag();
        void toggle_subtract_flag();
        void toggle_half_carry_flag();
        void toggle_carry_flag();


};

#endif // CPU_H