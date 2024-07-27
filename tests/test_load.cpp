#include <gtest/gtest.h>
#include <iostream>
#include <cstdint>

#include "load.h"
#include "cpu.h"

TEST(LoadTest, CanLoadOneRegisterIntoAnother) {
    CPU cpu;

    cpu.registers[B] = 20;
    
    LD::single_from_single(cpu, A, B);

    ASSERT_EQ(cpu.registers[A], cpu.registers[B]);
}

TEST(LoadTest, CanLoadValueFromAddressIntoSingleRegister) {
    CPU cpu;

    MemoryBus memory_bus;
    uint16_t address = 2555;
    uint8_t value = 32;

    memory_bus.write_to_memory(address, value);
    
    LD::single_from_address(cpu, memory_bus, A, address);

    ASSERT_EQ(cpu.registers[A], value);
}

TEST(LoadTest, CanLoadValueIntoSingleRegister) {
    CPU cpu;

    uint8_t value = 92;
    
    LD::single_from_value(cpu, A, value);

    ASSERT_EQ(cpu.registers[A], value);
}

TEST(LoadTest, CanLoadValueIntoMemory) {
    CPU cpu;
    MemoryBus memory_bus;

    uint8_t value = 32;
    uint16_t address = 2555;

    cpu.registers[D] = value;
    
    LD::to_address_from_single(cpu, memory_bus, address, D);

    auto value_in_memory = memory_bus.read_from_memory(address);

    ASSERT_EQ(value_in_memory, value);
}

TEST(LoadTest, CanLoadValueIntoDoubleRegister) {
    CPU cpu;

    uint16_t value_one = 92;
    uint16_t value_two = 20000;
    
    LD::double_from_value(cpu, BC, value_one);
    LD::double_from_value(cpu, HL, value_two);

    ASSERT_EQ(cpu.bc(), value_one);
    ASSERT_EQ(cpu.hl(), value_two);
}

