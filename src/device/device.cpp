#include "device.h"
#include "operations/bool.h"
#include "operations/compare.h"
#include "operations/general.h"
#include "operations/increment.h"
#include "operations/jump.h"
#include "operations/math.h"
#include "operations/rotate.h"
#include "operations/stack.h"
#include "operations/load.h"
#include "operations/compare.h"
#include "operations/call.h"


Device::Device(Cartridge cartridge) :
    current_game(cartridge),
    memory_bus(),
    cpu()
{

    // Set CPU Program Counter
    cpu.pc(0);
}

void Device::run() {
    while(true) {

        uint16_t value;
        // Get next opcode
        int code = read_from_memory(cpu.pc());
        // Execute opcode
        auto new_location = execute(code, value);

        // Update program counter
        cpu.pc(new_location);
    }
}

uint16_t Device::execute(const int code, int16_t value) {

    switch(code) {
        case 0: // NOP
            return NOP::run(cpu);
        case 1:
            return LD::double_from_value(cpu, BC, value);
        case 2:
            return LD::to_address_from_single(cpu, memory_bus, BC, A);
        case 3:
            return INC::pair(cpu, BC);
        case 4:
            return INC::single(cpu, B);
        case 5:
            return DEC::single(cpu, B);
        case 6:
            return LD::single_from_value(cpu, B, value);
        case 7:
            return Rotate::RLC(cpu, A);
        case 8:
            return LD::double_from_value(cpu, SP, value);
        case 9:
            return ADD::double_registers(cpu, HL, BC);
        case 10:
            return LD::single_from_address(cpu, memory_bus, A, BC);
        case 11:
            return DEC::pair(cpu, BC);
        case 12:
            return INC::single(cpu, C);
        case 13:
            return DEC::single(cpu, C);
        case 14:
            return LD::single_from_value(cpu, C, value);
        case 15:
            return Rotate::RRC(cpu, A);
        case 16:
            return STOP::run(cpu);
        case 17:
            return LD::double_from_value(cpu, DE, value);
        case 18:
            return LD::to_address_from_single(cpu, memory_bus, DE, A);
        case 19:
            return INC::pair(cpu, DE);
        case 20:
            return INC::single(cpu, D);
        case 21:
            return DEC::single(cpu, D);
        case 22:
            return LD::single_from_value(cpu, D, value);
        case 23:
            return Rotate::RL(cpu, A);
        case 24:
            return JR::by_adding(cpu, value);
        case 25:
            return ADD::double_registers(cpu, HL, DE);
        case 26:
            return LD::single_from_address(cpu, memory_bus, A, DE);
        case 27:
            return DEC::pair(cpu, DE);
        case 28:
            return INC::single(cpu, E);
        case 29:
            return DEC::single(cpu, E);
        case 30:
            return LD::single_from_value(cpu, E, value);
        case 31:
            return Rotate::RR(cpu, A);
        case 32:
            return JR::by_adding_if_not_flag(cpu, Zero, value);
        case 33:
            return LD::double_from_value(cpu, HL, value);
        case 34:
            return LD::to_address_from_single(cpu, memory_bus, HL, A, I);
        case 35:
            return INC::pair(cpu, HL);
        case 36:
            return INC::single(cpu, H);
        case 37:
            return DEC::single(cpu, H);
        case 38:
            return LD::single_from_value(cpu, H, value);
        case 39:
            return DAA::run(cpu);
        case 40:
            return JR::by_adding_if_flag(cpu, Zero, value);
        case 41:
            return ADD::double_registers(cpu, HL, HL);
        case 42:
            return LD::single_from_address(cpu, memory_bus, A, HL, I);
        case 43:
            return DEC::pair(cpu, HL);
        case 44:
            return INC::single(cpu, L);
        case 45:
            return DEC::single(cpu, L);
        case 46:
            return LD::single_from_value(cpu, L, value);
        case 47:
            return CPL::run(cpu);
        case 48:
            return JR::by_adding_if_not_flag(cpu, Carry, value);
        case 49:
            return LD::double_from_value(cpu, SP, value);
        case 50:
            return LD::to_address_from_single(cpu, memory_bus, HL, A, Dec);
        case 51:
            return INC::pair(cpu, SP);
        case 52:
            return INC::address(cpu, memory_bus, HL);
        case 53:
            return DEC::address(cpu, memory_bus, HL);
        case 54:
            return LD::double_from_value(cpu, HL, value);
        case 55:
            return SCF::run(cpu);
        case 56:
            return JR::by_adding_if_flag(cpu, Carry, value);
        case 57:
            return ADD::double_registers(cpu, HL, SP);
        case 58:
            return LD::single_from_address(cpu, memory_bus, A, HL, Dec);
        case 59:
            return DEC::pair(cpu, SP);
        case 60:
            return INC::single(cpu, A);
        case 61:
            return DEC::single(cpu, A);
        case 62:
            return LD::single_from_value(cpu, A, value);
        case 63:
            return CCF::run(cpu);
        case 64:
            return LD::single_from_single(cpu, B, B);
        case 65:
            return LD::single_from_single(cpu, B, C);
        case 66:
            return LD::single_from_single(cpu, B, D);
        case 67:
            return LD::single_from_single(cpu, B, E);
        case 68:
            return LD::single_from_single(cpu, B, H);
        case 69:
            return LD::single_from_single(cpu, B, L);
        case 70:
            return LD::single_from_address(cpu, memory_bus, B, HL);
        case 71:
            return LD::single_from_single(cpu, B, A);
        case 72:
            return LD::single_from_single(cpu, C, B);
        case 73:
            return LD::single_from_single(cpu, C, C);
        case 74:
            return LD::single_from_single(cpu, C, D);
        case 75:
            return LD::single_from_single(cpu, C, E);
        case 76:
            return LD::single_from_single(cpu, C, H);
        case 77:
            return LD::single_from_single(cpu, C, L);
        case 78:
            return LD::single_from_address(cpu, memory_bus, C, HL);
        case 79:
            return LD::single_from_single(cpu, C, L);
        case 80:
            return LD::single_from_single(cpu, D, B);
        case 81:
            return LD::single_from_single(cpu, D, C);
        case 82:
            return LD::single_from_single(cpu, D, D);
        case 83:
            return LD::single_from_single(cpu, D, E);
        case 84:
            return LD::single_from_single(cpu, D, H);
        case 85:
            return LD::single_from_single(cpu, D, L);
        case 86:
            return LD::single_from_address(cpu, memory_bus, D, HL);
        case 87:
            return LD::single_from_single(cpu, D, A);
        case 88:
            return LD::single_from_single(cpu, E, B);
        case 89:
            return LD::single_from_single(cpu, E, C);
        case 90:
            return LD::single_from_single(cpu, E, D);
        case 91:
            return LD::single_from_single(cpu, E, E);
        case 92:
            return LD::single_from_single(cpu, E, H);
        case 93:
            return LD::single_from_single(cpu, E, L);
        case 94:
            return LD::single_from_address(cpu, memory_bus, E, HL);
        case 95:
            return LD::single_from_single(cpu, E, A);
        case 96:
            return LD::single_from_single(cpu, H, B);
        case 97:
            return LD::single_from_single(cpu, H, C);
        case 98:
            return LD::single_from_single(cpu, H, D);
        case 99:
            return LD::single_from_single(cpu, H, E);
        case 100:
            return LD::single_from_single(cpu, H, H);
        case 101:
            return LD::single_from_single(cpu, H, L);
        case 102:
            return LD::single_from_address(cpu, memory_bus, H, HL);
        case 103:
            return LD::single_from_single(cpu, H, A);
        case 104:
            return LD::single_from_single(cpu, L, B);
        case 105:
            return LD::single_from_single(cpu, L, C);
        case 106:
            return LD::single_from_single(cpu, L, D);
        case 107:
            return LD::single_from_single(cpu, L, E);
        case 108:
            return LD::single_from_single(cpu, L, H);
        case 109:
            return LD::single_from_single(cpu, L, L);
        case 110:
            return LD::single_from_address(cpu, memory_bus, L, HL);
        case 111:
            return LD::single_from_single(cpu, L, A);
        case 112:
            return LD::to_address_from_single(cpu, memory_bus, HL, B);
        case 113:
            return LD::to_address_from_single(cpu, memory_bus, HL, C);
        case 114:
            return LD::to_address_from_single(cpu, memory_bus, HL, D);
        case 115:
            return LD::to_address_from_single(cpu, memory_bus, HL, E);
        case 116:
            return LD::to_address_from_single(cpu, memory_bus, HL, H);
        case 117:
            return LD::to_address_from_single(cpu, memory_bus, HL, L);
        case 118:
            return HALT::run(cpu);
        case 119:
            return LD::to_address_from_single(cpu, memory_bus, HL, A);
        case 120:
            return LD::single_from_single(cpu, A, B);
        case 121:
            return LD::single_from_single(cpu, A, C);
        case 122:
            return LD::single_from_single(cpu, A, D);
        case 123:
            return LD::single_from_single(cpu, A, E);
        case 124:
            return LD::single_from_single(cpu, A, H);
        case 125:
            return LD::single_from_single(cpu, A, L);
        case 126:
            return LD::single_from_address(cpu, memory_bus, A, HL);
        case 127:
            return LD::single_from_single(cpu, A, A);
        case 128:
            return ADD::single_registers(cpu, A, B);
        case 129:
            return ADD::single_registers(cpu, A, C);
        case 130:
            return ADD::single_registers(cpu, A, D);
        case 131:
            return ADD::single_registers(cpu, A, E);
        case 132:
            return ADD::single_registers(cpu, A, H);
        case 133:
            return ADD::single_registers(cpu, A, L);
        case 134:
            return ADD::to_single(cpu, memory_bus, A, HL);
        case 135:
            return ADD::single_registers(cpu, A, A);
        case 136:
            return ADC::single_registers(cpu ,A, B);
        case 137:
            return ADC::single_registers(cpu ,A, C);
        case 138:
            return ADC::single_registers(cpu ,A, D);
        case 139:
            return ADC::single_registers(cpu ,A, E);
        case 140:
            return ADC::single_registers(cpu ,A, H);
        case 141:
            return ADC::single_registers(cpu ,A, L);
        case 142:
            return ADC::to_single(cpu, memory_bus, A, HL);
        case 143:
            return ADC::single_registers(cpu ,A, A);
        case 144:
            return SUB::single_registers(cpu ,A, B);
        case 145:
            return SUB::single_registers(cpu ,A, C);
        case 146:
            return SUB::single_registers(cpu ,A, D);
        case 147:
            return SUB::single_registers(cpu ,A, E);
        case 148:
            return SUB::single_registers(cpu ,A, H);
        case 149:
            return SUB::single_registers(cpu ,A, L);
        case 150:
            return SUB::from_single(cpu, memory_bus, A, HL);
        case 151:
            return SUB::single_registers(cpu ,A, A);
        case 152:
            return SBC::single_registers(cpu ,A, B);
        case 153:
            return SBC::single_registers(cpu ,A, C);
        case 154:
            return SBC::single_registers(cpu ,A, D);
        case 155:
            return SBC::single_registers(cpu ,A, E);
        case 156:
            return SBC::single_registers(cpu ,A, H);
        case 157:
            return SBC::single_registers(cpu ,A, L);
        case 158:
            return SBC::from_single(cpu, memory_bus, A, HL);
        case 159:
            return SBC::single_registers(cpu ,A, A);
        case 160:
            return AND::with_register(cpu, B);
        case 161:
            return AND::with_register(cpu, C);
        case 162:
            return AND::with_register(cpu, D);
        case 163:
            return AND::with_register(cpu, E);
        case 164:
            return AND::with_register(cpu, H);
        case 165:
            return AND::with_register(cpu, L);
        case 166:
            return AND::with_address(cpu, memory_bus, HL);
        case 167:
            return AND::with_register(cpu, A);
        case 168:
            return XOR::with_register(cpu, B);
        case 169:
            return XOR::with_register(cpu, C);
        case 170:
            return XOR::with_register(cpu, D);
        case 171:
            return XOR::with_register(cpu, E);
        case 172:
            return XOR::with_register(cpu, H);
        case 173:
            return XOR::with_register(cpu, L);
        case 174:
            return XOR::with_address(cpu, memory_bus, HL);
        case 175:
            return XOR::with_register(cpu, A);
        case 176:
            return OR::with_register(cpu, B);
        case 177:
            return OR::with_register(cpu, C);
        case 178:
            return OR::with_register(cpu, D);
        case 179:
            return OR::with_register(cpu, E);
        case 180:
            return OR::with_register(cpu, H);
        case 181:
            return OR::with_register(cpu, L);
        case 182:
            return OR::with_address(cpu, memory_bus, HL);
        case 183:
            return OR::with_register(cpu, A);
        case 184:
            return CP::to_register(cpu, B);
        case 185:
            return CP::to_register(cpu, C);
        case 186:
            return CP::to_register(cpu, D);
        case 187:
            return CP::to_register(cpu, E);
        case 188:
            return CP::to_register(cpu, H);
        case 189:
            return CP::to_register(cpu, L);
        case 190:
            return CP::to_address_value(cpu, memory_bus, HL);
        case 191:
            return CP::to_register(cpu, A);
        case 192:
            return RET::run(cpu, memory_bus, ZeroOff);
        case 193:
            return POP::register_pair(cpu, memory_bus, B, C);
        case 194:
            return JP::to_address_if_flag_state(cpu, ZeroOff, value);
        case 195:
            return JP::to_address(cpu, value);
        case 196:
            return CALL::address_if_flag_state(cpu, memory_bus, ZeroOff, value);
        case 197:
            return PUSH::register_pair(cpu, memory_bus, B, C);
        case 198:
            return ADD::to_single(cpu, memory_bus, A, value);
        case 199:
            return RST::vector(cpu, memory_bus, x00);
        case 200:
            return RET::run(cpu, memory_bus, ZeroOn);
        case 201:
            return RET::run(cpu, memory_bus);
        case 202:
            return JP::to_address_if_flag_state(cpu, ZeroOn, value);
        case 203:
            return PREFIX();
        case 204:
            return CALL::address_if_flag_state(cpu, memory_bus, ZeroOn, value);
        case 205:
            return CALL::address(cpu, memory_bus, value);
        case 206:
            return ADC::to_single(cpu, A, value);
        case 207:
            return RST::vector(cpu, memory_bus, x08);
        case 208:
            return RET::run(cpu, memory_bus, CarryOff);
        case 209:
            return POP::register_pair(cpu, memory_bus, D, E);
        case 210:
            return JP::to_address_if_flag_state(cpu, CarryOff, value);
        case 212:
            return CALL::address_if_flag_state(cpu, memory_bus, CarryOff, value);
        case 213:
            return PUSH::register_pair(cpu, memory_bus, D, E);
        case 214:
            return SUB::from_single(cpu, A, value);
        case 215:
            return RST::vector(cpu, memory_bus, x10);
        case 216:
            return RET::run(cpu, memory_bus, CarryOn);
        case 217:
            return RETI::run(cpu, memory_bus);
        case 218:
            return JP::to_address_if_flag_state(cpu, CarryOn, value);
        case 220:
            return CALL::address_if_flag_state(cpu, memory_bus, CarryOn, value);
        case 222:
            return SBC::from_single(cpu, A, value);
        case 223:
            return RST::vector(cpu, memory_bus, x18);
        case 224:
            return LDIO::to_io_address_from_single(cpu, memory_bus, value, A);
        case 225:
            return POP::register_pair(cpu, memory_bus, H, L);
        case 226:
            return LDIO::to_io_single_from_single(cpu, memory_bus, C, A);
        case 229:
            return PUSH::register_pair(cpu, memory_bus, H, L);
        case 230:
            return ADD::to_single(cpu, A, value);
        case 231:
            return RST::vector(cpu, memory_bus, x20);
        case 232:
            return ADD::signed_integer(cpu, SP, value);
        case 233:
            return JP::to_address(cpu, HL);
        case 234:
            return LD::to_address_from_single(cpu, memory_bus, value, A);
        case 238:
            return XOR::with_value(cpu, value);
        case 239:
            return RST::vector(cpu, memory_bus, x28);
        case 240:
            return LDIO::to_single_from_io_address(cpu, memory_bus, A, value);
        case 241:
            return POP::register_pair(cpu, memory_bus, A, F);
        case 242:
            return LDIO::to_single_from_io_single(cpu, memory_bus, A, C);
        case 243:
            return DI::run(cpu);
        case 245:
            return PUSH::register_pair(cpu, memory_bus, A, F);
        case 246:
            return OR::with_value(cpu, value);
        case 247:
            return RST::vector(cpu, memory_bus, x30);
        case 248:
            return LD::double_from_double(cpu, HL, SP, value);
        case 249:
            return LD::double_from_double(cpu, SP, HL);
        case 250: 
            return LD::single_from_value(cpu, A, value);
        case 251:
            return EI::run(cpu);
        case 252:
            CP::to_value(cpu, value);
        case 253:
            RST::vector(cpu, memory_bus, x38);
        default:
            std::cerr << code << " does not exist." << std::endl;
    }

}