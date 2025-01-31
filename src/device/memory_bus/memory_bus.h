#ifndef MEMORY_BUS_H
#define MEMORY_BUS_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <iterator>
#include <sstream>
#include <iostream>

#include "cpu.h"

class MemoryBus {

    private:
        std::vector<uint8_t> rom;

    public:
        MemoryBus();
        uint8_t read_from_memory(uint16_t location);
        uint8_t get_next_in_memory(CPU& cpu);
        void write_to_memory(uint16_t location, uint8_t value);

};

#endif  // MEMORY_BUS_H