#ifndef GAMEBOY_H
#define GAMEBOY_H

#include <iostream>

#include "cpu.h"
#include "memory_bus.h"
#include "cartridge.h"

class Device {
    private:
        CPU cpu;
        MemoryBus memory_bus;
        Cartridge current_game;
        std::vector<char> rom;

        uint16_t NOP();
        uint16_t STOP();
        uint16_t HALT();

        // Two Register Operations

        void INC_16bit(std::string double_register);
        void DEC_16bit(std::string double_register);

        uint16_t LD_16bit(std::string double_register);

        // One Register Operations

        void INC_16bit(std::string double_register);
        void DEC_16bit(std::string double_register);

        uint16_t LD_8bit(std::string in_register);
        uint16_t LD_8bit_from_register(std::string in_register, std::string load_register);
        uint16_t LD_8bit_from_address(std::string in_register, std::string address_register);
        uint16_t LD_8bit_from_address(std::string address_register, std::string symbol, std::string load_register);
        uint16_t LD_8bit_to_address(std::string address_register, std::string load_register);
        uint16_t LD_8bit_to_address(std::string address_register, std::string symbol, std::string load_register);
        uint16_t LD_8bit_to_address(std::string address_register);

        uint16_t RLC(std::string in_register);

    public:
        Device(Cartridge cartridge);

        uint16_t execute(const int code);
        uint8_t read_from_memory(uint16_t location);
        void write_to_memory(uint16_t location, uint8_t value);

        void run();

};

#endif // GAMEBOY_H