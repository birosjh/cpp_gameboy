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

        int read_from_memory(int16_t program_counter);

    public:
        Device(Cartridge cartridge);

        uint16_t execute(const int code, uint16_t value);

        void run();

};

#endif // GAMEBOY_H