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

        // Add/Subtract Operation Functions

    public:
        Device(Cartridge cartridge);

        uint16_t execute(const int code);

        void run();

};

#endif // GAMEBOY_H