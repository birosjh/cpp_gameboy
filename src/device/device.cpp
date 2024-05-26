#include "device.h"

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
        // Get next opcode
        auto code = read_from_memory(cpu.pc());
        // Execute opcode
        auto new_location = execute();

        // Update program counter
        cpu.pc(new_location);
    }
}

uint16_t Device::execute(const int code) {

    switch(code) {
        case 0: // NOP
            return NOP();
        case 1:
            return LD_16bit("bc");
        case 2:
            return LD_8bit_to_address("bc", "a");
        case 3:
            return INC_16bit("bc");
        case 4:
            return INC_8bit("b");
        case 5:
            return DEC_8bit("b");
        case 6:
            return LD_8bit("b");
        case 7:
            return RLC("a");
        case 8:
            return LD_16bit_to_next("sp");
        case 9:
            return ADD_16bit("hl", "bc");
        case 10:
            return LD_8bit_from_address("a", "bc");
        case 11:
            return DEC_16bit("bc");
        case 12:
            return INC_8bit("c");
        case 13:
            return DEC_8bit("c");
        case 14:
            return LD_8bit("c");
        case 15:
            return RRC("a");
        case 16:
            return STOP();
        case 17:
            return LD_16bit("de");
        case 18:
            return LD_8bit_to_address("a", "de");
        case 19:
            return INC_16bit("de");
        case 20:
            return INC_8bit("d");
        case 21:
            return DEC_8bit("d");
        case 22:
            return LD_8bit("d");
        case 23:
            return RL("a");
        case 24:
            return JR();
        case 25:
            return ADD_16bit("hl", "de");
        case 26:
            return LD_8bit_from_address("a", "de");
        case 27:
            return DEC_16bit("de");
        case 28:
            return INC_8bit("e");
        case 29:
            return DEC_8bit("e");
        case 30:
            return LD_8bit("e");
        case 31:
            return RR("a");
        case 32:
            return JR("nz");
        case 33:
            return LD_16bit("hl");
        case 34:
            return LD_8bit_to_address("hl+", "a");
        case 35:
            return INC_16bit("hl");
        case 36:
            return INC_8bit("h");
        case 37:
            return DEC_8bit("h");
        case 38:
            return LD_8bit("h");
        case 39:
            return DAA();
        case 40:
            return JR("z")
        case 41:
            return ADD_16bit("hl", "hl");
        case 42:
            return LD_8bit_from_address("a", "+", "hl");
        case 43:
            return DEC_16bit("hl");
        case 44:
            return INC_8bit("l");
        case 45:
            return DEC_8bit("l");
        case 46:
            return LD_8bit("l");
        case 47:
            return CPL();
        case 48:
            return JR("nc");
        case 49:
            return LD_16bit("SP");
        case 50:
            return LD_8bit_to_address("hl", "-", "a");
        case 51:
            return INC_16bit("sp");
        case 52:
            return INC_address("hl");
        case 53:
            return DEC_address("hl");
        case 54:
            return LD_8bit_to_address("hl");
        case 55:
            return SCF();
        case 56:
            return JR("c");
        case 57:
            return ADD("hl", "sp");
        case 58:
            return LD_8bit_from_address("a", "-", "hl");
        case 59:
            return DEC_16bit("sp");
        case 60:
            return INC_8bit("a");
        case 61:
            return DEC_8bit("a");
        case 62:
            return LD_8bit("a");
        case 63:
            return CCF();
        case 64:
            return LD_8bit("b", "b");
        case 65:
            return LD_8bit("b", "c");
        case 66:
            return LD_8bit("b", "d");
        case 67:
            return LD_8bit("b", "e");
        case 68:
            return LD_8bit("b", "h");
        case 69:
            return LD_8bit("b", "l");
        case 70:
            return LD_8bit_from_address("b", "hl");
        case 71:
            return LD_8bit("b", "a");
        case 72:
            return LD_8bit("c", "b");
        case 73:
            return LD_8bit("c", "c");
        case 74:
            return LD_8bit("c", "d");
        case 75:
            return LD_8bit("c", "e");
        case 76:
            return LD_8bit("c", "h");
        case 77:
            return LD_8bit("c", "l");
        case 78:
            return LD_8bit_from_address("c", "hl");
        case 79:
            return LD_8bit("c", "a");
        case 80:
            return LD_8bit("d", "b");
        case 81:
            return LD_8bit("d", "c");
        case 82:
            return LD_8bit("d", "d");
        case 83:
            return LD_8bit("d", "e");
        case 84:
            return LD_8bit("d", "h");
        case 85:
            return LD_8bit("d", "l");
        case 86:
            return LD_8bit_from_address("d", "hl");
        case 87:
            return LD_8bit("d", "a");
        case 88:
            return LD_8bit("e", "b");
        case 89:
            return LD_8bit("e", "c");
        case 90:
            return LD_8bit("e", "d");
        case 91:
            return LD_8bit("e", "e");
        case 92:
            return LD_8bit("e", "h");
        case 93:
            return LD_8bit("e", "l");
        case 94:
            return LD_8bit_from_address("e", "hl");
        case 95:
            return LD_8bit("h", "a");
        case 96:
            return LD_8bit("h", "b");
        case 97:
            return LD_8bit("h", "c");
        case 98:
            return LD_8bit("h", "d");
        case 99:
            return LD_8bit("h", "e");
        case 100:
            return LD_8bit("h", "h");
        case 101:
            return LD_8bit("h", "l");
        case 102:
            return LD_8bit_from_address("h", "hl");
        case 103:
            return LD_8bit("h", "a");
        case 104:
            return LD_8bit("l", "b");
        case 105:
            return LD_8bit("l", "c");
        case 106:
            return LD_8bit("l", "d");
        case 107:
            return LD_8bit("l", "e");
        case 108:
            return LD_8bit("l", "h");
        case 109:
            return LD_8bit("l", "l");
        case 110:
            return LD_8bit_from_address("l", "hl");
        case 111:
            return LD_8bit("l", "a");
        case 112:
            return LD_8bit_to_address("hl", "b");
        case 113:
            return LD_8bit_to_address("hl", "c");
        case 114:
            return LD_8bit_to_address("hl", "d");
        case 115:
            return LD_8bit_to_address("hl", "e");
        case 116:
            return LD_8bit_to_address("hl", "h");
        case 117:
            return LD_8bit_to_address("hl", "l");
        case 118:
            return HALT();
        case 119:
            return LD_8bit_to_address("hl", "a");
        case 120:
            return LD_8bit("a", "b");
        case 121:
            return LD_8bit("a", "c");
        case 122:
            return LD_8bit("a", "d");
        case 123:
            return LD_8bit("a", "e");
        case 124:
            return LD_8bit("a", "h");
        case 125:
            return LD_8bit("a", "l");
        case 126:
            return LD_8bit_from_address("a", "hl");
        case 127:
            return LD_8bit("a", "a");
        case 128:
            return ADD("a", "b");
        case 129:
            return ADD("a", "c");
        case 130:
            return ADD("a", "d");
        case 131:
            return ADD("a", "e");
        case 132:
            return ADD("a", "h");
        case 133:
            return ADD("a", "l");
        case 134:
            return ADD_from_address("a", "hl");
        case 135:
            return ADD("a", "a");
        case 136:
            return ADC("a", "b");
        case 137:
            return ADC("a", "c");
        case 138:
            return ADC("a", "d");
        case 139:
            return ADC("a", "e");
        case 140:
            return ADC("a", "h");
        case 141:
            return ADC("a", "l");
        case 142:
            return ADC_from_address("a", "hl");
        case 143:
            return ADC("a", "a");
        case 144:
            return SUB("a", "b");
        case 145:
            return SUB("a", "c");
        case 146:
            return SUB("a", "d");
        case 147:
            return SUB("a", "e");
        case 148:
            return SUB("a", "h");
        case 149:
            return SUB("a", "l");
        case 150:
            return SUB_from_address("a", "hl");
        case 151:
            return SUB("a", "a");
        case 152:
            return SBC("a", "b");
        case 153:
            return SBC("a", "c");
        case 154:
            return SBC("a", "d");
        case 155:
            return SBC("a", "e");
        case 156:
            return SBC("a", "h");
        case 157:
            return SBC("a", "l");
        case 158:
            return SBC_from_address("a", "hl");
        case 159:
            return SBC("a", "a");
        case 160:
            return AND("a", "b");
        case 161:
            return AND("a", "c");
        case 162:
            return AND("a", "d");
        case 163:
            return AND("a", "e");
        case 164:
            return AND("a", "h");
        case 165:
            return AND("a", "l");
        case 166:
            return AND_from_address("a", "hl");
        case 167:
            return AND("a", "a");
        case 168:
            return XOR("a", "b");
        case 169:
            return XOR("a", "c");
        case 170:
            return XOR("a", "d");
        case 171:
            return XOR("a", "e");
        case 172:
            return XOR("a", "h");
        case 173:
            return XOR("a", "l");
        case 174:
            return XOR_from_address("a", "hl");
        case 175:
            return XOR("a", "a");
        case 176:
            return OR("a", "b");
        case 177:
            return OR("a", "c");
        case 178:
            return OR("a", "d");
        case 179:
            return OR("a", "e");
        case 180:
            return OR("a", "h");
        case 181:
            return OR("a", "l");
        case 182:
            return OR_from_address("a", "hl");
        case 183:
            return OR("a", "a");
        case 184:
            return CP("a", "b");
        case 185:
            return CP("a", "c");
        case 186:
            return CP("a", "d");
        case 187:
            return CP("a", "e");
        case 188:
            return CP("a", "h");
        case 189:
            return CP("a", "l");
        case 190:
            return CP_from_address("a", "hl");
        case 191:
            return CP("a", "a");
        case 192:
            return RET("nz");
        case 193:
            return POP("bc");
        case 194:
            return JP("nz");
        case 195:
            return JP();
        case 196:
            return CALL("nz");
        case 197:
            return PUSH("bc");
        case 198:
            return ADD("a");
        case 199:
            return RST("00h");
        case 200:
            return RET("z");
        case 201:
            return RET();
        case 202:
            return JP("z");
        case 203:
            return PREFIX()
        case 204:
            return CALL("z");
        case 205:
            return CALL();
        case 206:
            return ADC("a"),
        case 207:
            return RST("08h");
        case 208:
            return RET("nc");
        case 209:
            return POP("de");
        case 210:
            return JP("nc");
        case 212:
            return CALL("nc");
        case 213:
            return PUSH("de");
        case 214:
            return SUB("a");
        case 215:
            return RST("10h");
        case 216:
            return RET("c");
        case 217:
            return RETI();
        case 218:
            return JP("c");
        case 220:
            return CALL("c");
        case 222:
            return SBC("a");
        case 223:
            return RST("18h");
        case 224:
            return LD_special("a");
        case 225:
            return POP("hl");
        case 226:
            return LD_special("c", "a");
        case 229:
            return PUSH("hl");
        case 230:
            return ADD("a");
        case 231:
            return RST("20h");
        case 232:
            return ADD_16bit("sp");
        case 233:
            return JP("hl");
        case 234:
            return LD_8bit_to_address("a");
        case 238:
            return XOR("a");
        case 239:
            return RST("28h");
        case 240:
            return LD_special("a");
        case 241:
            return POP("AF");
        case 242:
            return DI();
        case 244:
            return PUSH("af");
        case 245:
            return OR("a");
        case 246:
            return RST("30h");
        case 247:
            return LD_and_increment("hl", "sp");
        case 248:
            return LD_16bit("sp", "hl");
        case 249:
            return EI();
        case 252:
            CP("a");
        case 253:
            RST("38h");
        
        default:
            std::cerr << code << " does not exist." std::endl;
    }

}