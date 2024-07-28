#include <gtest/gtest.h>
#include <iostream>
#include <cstdint>

#include "math.h"
#include "cpu.h"
#include "memory_bus.h"

// Single Register Tests

TEST(AddTest, RegistersCanBeAdded) {
    CPU cpu;

    cpu.registers[A] = 5;
    cpu.registers[B] = 5;

    uint8_t expected_value = 10;

    ADD::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(AddTest, AddResultingInZeroSetsFlag) {
    CPU cpu;

    cpu.registers[A] = 255;
    cpu.registers[B] = 1;

    ADD::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.flags[Zero], true);
}

TEST(AddTest, AddUsingHalfCarrySetsHalfCarryFlag) {
    CPU cpu;

    cpu.registers[A] = 62;
    cpu.registers[B] = 34;

    ADD::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.flags[HalfCarry], true);
}

TEST(AddTest, AddressValuesCanBeAddedToRegisters) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 22;

    memory_bus.write_to_memory(address, 9);

    cpu.registers[A] = 10;

    ADD::to_single_using_address(cpu, memory_bus, A, address);

    ASSERT_EQ(cpu.registers[A], 19);
}


TEST(AddCarryTest, RegistersCanBeAddedWithCarry) {
    CPU cpu;

    cpu.registers[A] = 5;
    cpu.registers[B] = 5;

    cpu.flags[Carry] = true;

    uint8_t expected_value = 11;

    ADC::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(AddCarryTest, AddCarryUsingHalfCarrySetsHalfCarryFlag) {
    CPU cpu;

    cpu.registers[A] = 62;
    cpu.registers[B] = 34;

    ADC::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.flags[HalfCarry], true);
}

TEST(AddCarryTest, AddressValuesCanBeAddedToRegistersWithCarry) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 22;

    cpu.flags[Carry] = true;

    memory_bus.write_to_memory(address, 9);

    cpu.registers[A] = 10;

    ADC::to_single_using_address(cpu, memory_bus, A, address);

    ASSERT_EQ(cpu.registers[A], 20);
}


TEST(SubTest, RegistersCanBeSubtracted) {
    CPU cpu;

    uint8_t expected_value = 5;

    cpu.registers[A] = 10;
    cpu.registers[B] = 5;

    SUB::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

TEST(SubTest, SubtractionResultingInZeroSetsZeroFlag) {
    CPU cpu;

    cpu.registers[A] = 10;
    cpu.registers[B] = 10;

    SUB::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.flags[Zero], true);
}

TEST(SubTest, SubtractionSetsNegativeFlag) {
    CPU cpu;

    cpu.registers[A] = 10;
    cpu.registers[B] = 5;

    SUB::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.flags[Negative], true);
}


TEST(SubTest, AddressValuesCanBeSubtractedFromRegisters) {
    CPU cpu;
    MemoryBus memory_bus;

    uint16_t address = 22;

    memory_bus.write_to_memory(address, 9);

    cpu.registers[A] = 10;

    SUB::from_single_using_address(cpu, memory_bus, A, address);

    ASSERT_EQ(cpu.registers[A], 1);
}

TEST(SubCarryTest, RegistersCanBeSubtractedWithCarry) {
    CPU cpu;

    cpu.flags[Carry] = true;

    uint8_t expected_value = 4;

    cpu.registers[A] = 10;
    cpu.registers[B] = 5;

    SBC::single_registers(cpu, A, B);

    ASSERT_EQ(cpu.registers[A], expected_value);
}

// Double Register Tests

TEST(AddTest, DoubleRegistersCanBeAdded) {
    CPU cpu;

    auto value_one = 3000;
    auto value_two = 2000;

    cpu.double_register(HL, value_one);
    cpu.double_register(BC, value_two);

    uint16_t expected_value = value_one + value_two;

    ADD::double_registers(cpu, HL, BC);

    ASSERT_EQ(cpu.double_register(HL), expected_value);
}

TEST(AddTest, DoubleAddUsingHalfCarrySetsHalfCarryFlag) {
    CPU cpu;

    auto value_one = 4095;
    auto value_two = 1;

    cpu.double_register(HL, value_one);
    cpu.double_register(BC, value_two);

    ADD::double_registers(cpu, HL, BC);

    ASSERT_EQ(cpu.flags[HalfCarry], true);
}




