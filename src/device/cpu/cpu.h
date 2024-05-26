#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include <unordered_map>

class CPU {
    private:
        static const uint8_t zero_flag_position = 7;
        static const uint8_t subtract_flag_position = 6;
        static const uint8_t half_carry_flag_position = 5;
        static const uint8_t carry_flag_position = 4;

        uint16_t stack_pointer;
        uint16_t program_counter;

    public:

        std::unordered_map<std::string, uint8_t> registers =
        {
            {"a", 0},
            {"b", 0},
            {"c", 0},
            {"d", 0},
            {"e", 0},
            {"f", 0},
            {"h", 0},
            {"l", 0},
        };
        
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


        void toggle_zero_flag();
        void toggle_subtract_flag();
        void toggle_half_carry_flag();
        void toggle_carry_flag();


};

#endif // CPU_H