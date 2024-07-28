#include <gtest/gtest.h>
#include <iostream>

#include "cpu.h"
#include "compare.h"

TEST(CompareTest, ZeroFlagSetWhenCompareIsZero) {
    CPU cpu;

    cpu.registers[A] = 5;
    cpu.registers[B] = 5;

    CP::to_register(cpu, B);

    ASSERT_EQ(cpu.flags[Zero], true);
}

TEST(CompareTest, HalfCarryGetsSet) {
    CPU cpu;

    cpu.registers[A] = 16;
    cpu.registers[B] = 8;

    CP::to_register(cpu, B);

    ASSERT_EQ(cpu.flags[HalfCarry], true);

}

TEST(CompareTest, NegativeGetsSet) {
    CPU cpu;

    cpu.registers[A] = 10;
    cpu.registers[B] = 5;

    CP::to_register(cpu, B);

    ASSERT_EQ(cpu.flags[Negative], true);
}

