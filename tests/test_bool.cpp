#include <gtest/gtest.h>
#include <iostream>

#include "bool.h"

// AND Tests

TEST(AndTest, AndComparisonResultsInContentsSavingToA) {
    CPU cpu;

    uint8_t expected_value = 1;

    cpu.registers[A] = 1;
    cpu.registers[B] = 1;

    AND::with_register(cpu, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(AndTest, OperationResultingInZeroSetsZeroFlag) {
    CPU cpu;

    uint8_t expected_value = 0;

    cpu.registers[A] = 1;
    cpu.registers[B] = 2;

    AND::with_register(cpu, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(AndTest, AndWithValueSavesToA) {
    CPU cpu;

    uint8_t value = 5;
    uint8_t expected_value = 5;

    cpu.registers[A] = 5;

    AND::with_value(cpu, value);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(AndTest, AndWithAddressSavesToA) {
    CPU cpu;
    MemoryBus memory_bus;

    uint8_t expected_value = 5;

    uint16_t address = 2000;
    memory_bus.write_to_memory(2000, expected_value);

    cpu.registers[A] = expected_value;

    AND::with_address(cpu, memory_bus, address);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

// OR Tests

TEST(OrTest, OrComparisonResultsInContentsSavingToA) {
    CPU cpu;

    uint8_t expected_value = 1;

    cpu.registers[A] = 1;
    cpu.registers[B] = 1;

    OR::with_register(cpu, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(OrTest, OperationResultingInZeroSetsZeroFlag) {
    CPU cpu;

    uint8_t expected_value = 0;

    cpu.registers[A] = 0;
    cpu.registers[B] = 0;

    OR::with_register(cpu, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(OrTest, OrWithValueSavesToA) {
    CPU cpu;

    uint8_t value = 5;
    uint8_t expected_value = 5;

    cpu.registers[A] = 5;

    OR::with_value(cpu, value);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(OrTest, OrWithAddressSavesToA) {
    CPU cpu;
    MemoryBus memory_bus;

    uint8_t expected_value = 5;

    uint16_t address = 2000;
    memory_bus.write_to_memory(2000, expected_value);

    cpu.registers[A] = expected_value;

    OR::with_address(cpu, memory_bus, address);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

// XOR Tests

TEST(XorTest, XorComparisonResultsInContentsSavingToA) {
    CPU cpu;

    uint8_t expected_value = 3;

    cpu.registers[A] = 1;
    cpu.registers[B] = 2;

    XOR::with_register(cpu, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(XorTest, OperationResultingInZeroSetsZeroFlag) {
    CPU cpu;

    uint8_t expected_value = 0;

    cpu.registers[A] = 255;
    cpu.registers[B] = 255;

    XOR::with_register(cpu, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(XorTest, XorWithValueSavesToA) {
    CPU cpu;

    uint8_t value = 8;

    cpu.registers[A] = 16;

    XOR::with_value(cpu, value);

    uint8_t expected_value = 24;
    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(XorTest, XorWithAddressSavesToA) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 2000;
    memory_bus.write_to_memory(2000, 4);

    cpu.registers[A] = 1;

    XOR::with_address(cpu, memory_bus, address);

    uint8_t expected_value = 5;
    ASSERT_EQ(cpu.registers[A], expected_value);
}