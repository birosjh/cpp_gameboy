#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include <unordered_map>


class CPU {
    private:
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
            {"h", 0},
            {"l", 0},
        };

        std::unordered_map<std::string, bool> flags =
        {
            {"z", false},
            {"n", false},
            {"h", false},
            {"c", false},
        };

        uint16_t double_register(std::string register_name);
        void double_register(std::string register_name, uint16_t value);
        
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