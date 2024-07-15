#include <gtest/gtest.h>
#include <iostream>
#include <cstdint>

#include "math.h"
#include "cpu.h"
#include "memory_bus.h"

TEST(AddTest, RegistersCanBeAdded) {
    CPU cpu;

    cpu.registers["a"] = 5;
    cpu.registers["b"] = 5;

    uint8_t expected_value = 10;

    ADD::single_registers(cpu, "a", "b");

    ASSERT_EQ(cpu.registers["a"], expected_value);
}

TEST(AddTest, AddResultingInZeroSetsFlag) {
    CPU cpu;

    cpu.registers["a"] = 255;
    cpu.registers["b"] = 1;

    ADD::single_registers(cpu, "a", "b");

    ASSERT_EQ(cpu.flags["z"], true);
}

TEST(AddTest, AddUsingHalfCarrySetsHalfCarryFlag) {
    CPU cpu;

    cpu.registers["a"] = 62;
    cpu.registers["b"] = 34;

    ADD::single_registers(cpu, "a", "b");

    ASSERT_EQ(cpu.flags["h"], true);
}

TEST(AddTest, AddressValuesCanBeSubtractedFromRegisters) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 22;

    memory_bus.write_to_memory(address, 9);

    cpu.registers["a"] = 10;

    ADD::to_single_using_address(cpu, memory_bus, "a", address);

    ASSERT_EQ(cpu.registers["a"], 19);
}


TEST(SubTest, RegistersCanBeSubtracted) {
    CPU cpu;

    uint8_t expected_value = 5;

    cpu.registers["a"] = 10;
    cpu.registers["b"] = 5;

    SUB::single_registers(cpu, "a", "b");

    ASSERT_EQ(cpu.registers["a"], expected_value);
}

TEST(SubTest, SubtractionResultingInZeroSetsZeroFlag) {
    CPU cpu;

    cpu.registers["a"] = 10;
    cpu.registers["b"] = 10;

    SUB::single_registers(cpu, "a", "b");

    ASSERT_EQ(cpu.flags["z"], true);
}

TEST(SubTest, SubtractionSetsNegativeFlag) {
    CPU cpu;

    cpu.registers["a"] = 10;
    cpu.registers["b"] = 5;

    SUB::single_registers(cpu, "a", "b");

    ASSERT_EQ(cpu.flags["n"], true);
}


TEST(SubTest, AddressValuesCanBeSubtractedFromRegisters) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 22;

    memory_bus.write_to_memory(address, 9);

    cpu.registers["a"] = 10;

    SUB::from_single_using_address(cpu, memory_bus, "a", address);

    ASSERT_EQ(cpu.registers["a"], 1);
}




