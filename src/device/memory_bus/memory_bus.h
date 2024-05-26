#ifndef MEMORY_BUS_H
#define MEMORY_BUS_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdint>

class MemoryBus {

    private:
        std::vector<char> rom;

    public:
        MemoryBus();
        uint8_t read_from_memory(uint16_t location);
        void write_to_memory(uint16_t location, uint8_t value);

        

};

#endif  // MEMORY_BUS_H