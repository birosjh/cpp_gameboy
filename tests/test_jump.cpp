#include <gtest/gtest.h>

#include "jump.h"

TEST(JumpTest, CanJumpToAddress) {
    CPU cpu;

    uint16_t value = 2000;
    
    JP::to_address(cpu, value);

    ASSERT_EQ(cpu.pc(), value);
}

TEST(JumpTest, CanJumpToValueInDoubleRegister) {
    CPU cpu;

    uint16_t value = 2000;

    cpu.hl(value);
    
    JP::to_address_in_register(cpu, HL);

    ASSERT_EQ(cpu.pc(), value);
}

TEST(JumpTest, CanJumpIfZeroFlagSet) {
    CPU cpu;

    uint16_t value = 2000;

    Flag flag = Zero;

    // Flag Off

    auto original_value = cpu.pc();

    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), original_value);

    // Flag On

    cpu.flags[flag] = true;
    
    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), value);
}

TEST(JumpTest, CanJumpIfCarryFlagSet) {
    CPU cpu;

    uint16_t value = 2000;

    Flag flag = Carry;

    // Flag Off

    auto original_value = cpu.pc();

    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), original_value);

    // Flag On

    cpu.flags[flag] = true;
    
    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), value);
}

TEST(JumpTest, CanJumpIfHalfCarryFlagSet) {
    CPU cpu;

    uint16_t value = 2000;

    Flag flag = HalfCarry;

    // Flag Off

    auto original_value = cpu.pc();

    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), original_value);

    // Flag On

    cpu.flags[flag] = true;
    
    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), value);
}

TEST(JumpTest, CanJumpIfNegativeFlagSet) {
    CPU cpu;

    uint16_t value = 2000;

    Flag flag = Negative;

    // Flag Off

    auto original_value = cpu.pc();

    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), original_value);

    // Flag On

    cpu.flags[flag] = true;
    
    JP::to_address_if_flag(cpu, flag, value);

    ASSERT_EQ(cpu.pc(), value);
}

