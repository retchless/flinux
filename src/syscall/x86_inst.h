/* Instruction description tables */
#define INST_TYPE_NOP			0 /* Instruction which are out of interest */
#define INST_TYPE_UNKNOWN		1 /* Unknown/not implemented */
#define INST_TYPE_MODRM			3 /* Instruction containing a memory address in ModR/M opcode */
#define INST_TYPE_MOV_MOFFSET	4 /* MOV moffset series instructions */
#define INST_TYPE_EXTENSION(x)	(32 + (x)) /* Instruction with opcode extension */
#define SIZE_DEPENDS_ON_PREFIX	-1 /* Indicate imm_bytes is 2 or 4 depends on operand size prefix */
struct instruction_desc
{
	int type; /* Instruction type */
	int imm_bytes; /* Bytes after ModR/M opcode, or SIZE_DEPENDS_ON_PREFIX */
};
#define NOP()			{ .type = INST_TYPE_NOP },
#define UNKNOWN()		{ .type = INST_TYPE_UNKNOWN },
#define MODRM(i)		{ .type = INST_TYPE_MODRM, .imm_bytes = (i) },
#define MOV_MOFFSET()	{ .type = INST_TYPE_MOV_MOFFSET },
#define EXTENSION(x)	{ .type = INST_TYPE_EXTENSION(x) },

/* AX */
#define AX()			NOP()
/* CX */
#define CX()			NOP()
/* DX */
#define DX()			NOP()
/* BX */
#define BX()			NOP()
/* SP */
#define SP()			NOP()
/* BP */
#define BP()			NOP()
/* SI */
#define SI()			NOP()
/* DI */
#define DI()			NOP()
/* EAX */
#define EAX()			NOP()
/* ECX */
#define ECX()			NOP()
/* EDX */
#define EDX()			NOP()
/* EBX */
#define EBX()			NOP()
/* ESP */
#define ESP()			NOP()
/* EBP */
#define EBP()			NOP()
/* ESI */
#define ESI()			NOP()
/* EDI */
#define EDI()			NOP()
/* AX or EAX (depends on operand size prefix) */
#define AX_EAX()		NOP()
/* CX or ECX (depends on operand size prefix) */
#define CX_ECX()		NOP()
/* DX or EDX (depends on operand size prefix) */
#define DX_EDX()		NOP()
/* BX or EBX (depends on operand size prefix) */
#define BX_EBX()		NOP()
/* SP or ESP (depends on operand size prefix) */
#define SP_ESP()		NOP()
/* BP or EBP (depends on operand size prefix) */
#define BP_EBP()		NOP()
/* SI or ESI (depends on operand size prefix) */
#define SI_ESI()		NOP()
/* DI or EDI (depends on operand size prefix) */
#define DI_EDI()		NOP()

/* OP imm8 */
#define IMM8()			NOP()
/* OP imm16 */
#define IMM16()			NOP()
/* OP imm32 */
#define IMM32()			NOP()
/* OP imm16; or OP imm32 (depends on operand size prefix) */
#define IMM16_IMM32()	NOP()
/* OP imm16, imm8 */
#define IMM16_IMM8()	NOP()
/* OP rel8 */
#define REL8()			NOP()
/* OP rel16 */
#define REL16()			NOP()
/* OP rel32 */
#define REL_32()		NOP()
/* OP rel16; or OP rel32 (depends on operand size prefix) */
#define REL16_REL32()	NOP()
/* OP ptr16:16; or OP ptr16:32 (depends on operand size prefix) */
#define PTR16_16_PTR16_32()	NOP()

/* OP AL, imm8 */
#define AL_IMM8()		NOP()
/* OP AL, DX */
#define AL_DX()			NOP()
/* OP AX, DX; or OP EAX, DX (depends on operand size prefix) */
#define AX_DX_EAX_DX()	NOP()
/* OP AX, imm8; or OP EAX, imm8 (depends on operand size prefix) */
#define AX_IMM8_EAX_IMM8()		NOP()
/* OP AX, imm16; or OP EAX, imm32 (depends on operand size prefix) */
#define AX_IMM16_EAX_IMM32()	NOP()

/* OP r/m8 */
#define RM8()			MODRM(0)
/* OP r/m8, 1 */
#define RM8_1()			MODRM(0)
/* OP r/m8, CL */
#define RM8_CL()		MODRM(0)
/* OP r/m16 */
#define RM16()			MODRM(0)
/* OP r/m32 */
#define RM32()			MODRM(0)
/* OP r/m16; or OP r/m32 (depends on operand size prefix) */
#define RM16_RM32()		MODRM(0)
/* OP r/m16, 1; or OP r/m32, 1 (depends on operand size prefix) */
#define RM16_1_RM32_1()		MODRM(0)
/* OP r/m16, CL; or OP r/m32, CL (depends on operand size prefix) */
#define RM16_CL_RM32_CL()	MODRM(0)

/* OP r/m8, r8 */
#define RM8_R8()		MODRM(0)
/* OP r/m16, r16 */
#define RM16_R16()		MODRM(0)
/* OP r/m32, r32 */
#define RM32_R32()		MODRM(0)
/* OP r/m16, r16; or OP r/m32, r32 (depends on operand size prefix) */
#define RM16_R16_RM32_R32()		MODRM(0)

/* OP r/m8, imm8 */
#define RM8_IMM8()		MODRM(1)
/* OP r/m16, imm16 */
#define RM16_IMM16()	MODRM(2)
/* OP r/m32, imm32 */
#define RM32_IMM32()	MODRM(4)
/* OP r/m16, imm8; or OP r/m32, imm8 (depends on operand size prefix) */
#define RM16_IMM8_RM32_IMM8()	MODRM(1)
/* OP r/m16, imm16; or OP r/m32, imm32 (depends on operand size prefix) */
#define RM16_IMM16_RM32_IMM32()	MODRM(SIZE_DEPENDS_ON_PREFIX)

/* OP r8, r/m8 */
#define R8_RM8()		MODRM(0)
/* OP r16, r/m16 */
#define R16_RM16()		MODRM(0)
/* OP r32, r/m16 */
#define R32_RM16()		MODRM(0)
/* OP r32, r/m32 */
#define R32_RM32()		MODRM(0)
/* OP r16, r/m8; or OP r32, r/m8 (depends on operand size prefix) */
#define R16_RM8_R32_RM8()	MODRM(0)
/* OP r16, r/m16; or OP r32, r/m32 (depends on operand size prefix) */
#define R16_RM16_R32_RM32()		MODRM(0)
/* OP r16, m16&16; or OP r32, m32&32 (depends on operand size prefix) */
#define R16_M1616_R32_M3232()	MODRM(0)
/* OP r16, r/m16, imm8; or OP r32, r/m32, imm8 (depends on operand size prefix) */
#define R16_RM16_IMM8_R32_RM32_IMM8()	MODRM(1)
/* OP r16, r/m16, imm16; or OP r32, r/m32, imm32 (depends on operand size prefix) */
#define R16_RM16_IMM16_R32_RM32_IMM32()	MODRM(SIZE_DEPENDS_ON_PREFIX)
/* OP r16, m16:16; or OP r32, m16:32 (depends on operand size prefix) */
#define R16_M16_16_R32_M16_32()			MODRM(0)

static const struct instruction_desc one_byte_inst[256] =
{
	/* 0x00: ADD */ RM8_R8()
	/* 0x01: ADD */ RM16_R16_RM32_R32()
	/* 0x02: ADD */ R8_RM8()
	/* 0x03: ADD */ R16_RM16_R32_RM32()
	/* 0x04: ADD */ AL_IMM8()
	/* 0x05: ADD */ AX_IMM16_EAX_IMM32()
	/* 0x06: ??? */ UNKNOWN()
	/* 0x07: ??? */ UNKNOWN()
	/* 0x08: OR */ RM8_R8()
	/* 0x09: OR */ RM16_R16_RM32_R32()
	/* 0x0A: OR */ R8_RM8()
	/* 0x0B: OR */ R16_RM16_R32_RM32()
	/* 0x0C: OR */ AL_IMM8()
	/* 0x0D: OR */ AX_IMM16_EAX_IMM32()
	/* 0x0E: ??? */ UNKNOWN()
	/* 0x0F: ??? */ UNKNOWN()
	/* 0x10: ADC */ RM8_R8()
	/* 0x11: ADC */ RM16_R16_RM32_R32()
	/* 0x12: ADC */ R8_RM8()
	/* 0x13: ADC */ R16_RM16_R32_RM32()
	/* 0x14: ADC */ AL_IMM8()
	/* 0x15: ADC */ AX_IMM16_EAX_IMM32()
	/* 0x16: ??? */ UNKNOWN()
	/* 0x17: ??? */ UNKNOWN()
	/* 0x18: SBB */ RM8_R8()
	/* 0x19: SBB */ RM16_R16_RM32_R32()
	/* 0x1A: SBB */ R8_RM8()
	/* 0x1B: SBB */ R16_RM16_R32_RM32()
	/* 0x1C: SBB */ AL_IMM8()
	/* 0x1D: SBB */ AX_IMM16_EAX_IMM32()
	/* 0x1E: ??? */ UNKNOWN()
	/* 0x1F: ??? */ UNKNOWN()
	/* 0x20: AND */ RM8_R8()
	/* 0x21: AND */ RM16_R16_RM32_R32()
	/* 0x22: AND */ R8_RM8()
	/* 0x23: AND */ R16_RM16_R32_RM32()
	/* 0x24: AND */ AL_IMM8()
	/* 0x25: AND */ AX_IMM16_EAX_IMM32()
	/* 0x26: ??? */ UNKNOWN()
	/* 0x27: DAA */ NOP()
	/* 0x28: SUB */ RM8_R8()
	/* 0x29: SUB */ RM16_R16_RM32_R32()
	/* 0x2A: SUB */ R8_RM8()
	/* 0x2B: SUB */ R16_RM16_R32_RM32()
	/* 0x2C: SUB */ AL_IMM8()
	/* 0x2D: SUB */ AX_IMM16_EAX_IMM32()
	/* 0x2E: ??? */ UNKNOWN()
	/* 0x2F: DAS */ NOP()
	/* 0x30: XOR */ RM8_R8()
	/* 0x31: XOR */ RM16_R16_RM32_R32()
	/* 0x32: XOR */ R8_RM8()
	/* 0x33: XOR */ R16_RM16_R32_RM32()
	/* 0x34: XOR */ AL_IMM8()
	/* 0x35: XOR */ AX_IMM16_EAX_IMM32()
	/* 0x36: ??? */ UNKNOWN()
	/* 0x37: AAA */ NOP()
	/* 0x38: CMP */ RM8_R8()
	/* 0x39: CMP */ RM16_R16_RM32_R32()
	/* 0x3A: CMP */ R8_RM8()
	/* 0x3B: CMP */ R16_RM16_R32_RM32()
	/* 0x3C: CMP */ AL_IMM8()
	/* 0x3D: CMP */ AX_IMM16_EAX_IMM32()
	/* 0x3E: ??? */ UNKNOWN()
	/* 0x3F: AAS */ NOP()
	/* 0x40: INC */ AX_EAX()
	/* 0x41: INC */ CX_ECX()
	/* 0x42: INC */ DX_EDX()
	/* 0x43: INC */ BX_EBX()
	/* 0x44: INC */ SP_ESP()
	/* 0x45: INC */ BP_EBP()
	/* 0x46: INC */ SI_ESI()
	/* 0x47: INC */ DI_EDI()
	/* 0x48: DEC */ AX_EAX()
	/* 0x49: DEC */ CX_ECX()
	/* 0x4A: DEC */ DX_EDX()
	/* 0x4B: DEC */ BX_EBX()
	/* 0x4C: DEC */ SP_ESP()
	/* 0x4D: DEC */ BP_EBP()
	/* 0x4E: DEC */ SI_ESI()
	/* 0x4F: DEC */ DI_EDI()
	/* 0x50: PUSH */ EAX()
	/* 0x51: PUSH */ ECX()
	/* 0x52: PUSH */ EDX()
	/* 0x53: PUSH */ EBX()
	/* 0x54: PUSH */ ESP()
	/* 0x55: PUSH */ EBP()
	/* 0x56: PUSH */ ESI()
	/* 0x57: PUSH */ EDI()
	/* 0x58: POP */ EAX()
	/* 0x59: POP */ ECX()
	/* 0x5A: POP */ EDX()
	/* 0x5B: POP */ EBX()
	/* 0x5C: POP */ ESP()
	/* 0x5D: POP */ EBP()
	/* 0x5E: POP */ ESI()
	/* 0x5F: POP */ EDI()
	/* 0x60: PUSHA_PUSHAD */ NOP()
	/* 0x61: POPA/POPAD */ NOP()
	/* 0x62: BOUND */ R16_M1616_R32_M3232()
	/* 0x63: ARPL */ RM16_R16()
	/* 0x64: ??? */ UNKNOWN()
	/* 0x65: ??? */ UNKNOWN()
	/* 0x66: ??? */ UNKNOWN()
	/* 0x67: ??? */ UNKNOWN()
	/* 0x68: ??? */ UNKNOWN()
	/* 0x69: IMUL */ R16_RM16_IMM16_R32_RM32_IMM32()
	/* 0x6A: ??? */ UNKNOWN()
	/* 0x6B: IMUL */ R16_RM16_IMM8_R32_RM32_IMM8()
	/* 0x6C: INSB */ NOP()
	/* 0x6D: INSW/INSD */ NOP()
	/* 0x6E: OUTSB */ NOP()
	/* 0x6F: OUTSW/OUTSD */ NOP()
	/* 0x70: JO */ REL8()
	/* 0x71: JNO */ REL8()
	/* 0x72: JB/JC/JNAE */ REL8()
	/* 0x73: JAE/JNB/JNC */ REL8()
	/* 0x74: JE/JZ */ REL8()
	/* 0x75: JNE/JNZ */ REL8()
	/* 0x76: JBE/JNA */ REL8()
	/* 0x77: JA/JNBE */ REL8()
	/* 0x78: JS */ REL8()
	/* 0x79: JNS */ REL8()
	/* 0x7A: JP/JPE */ REL8()
	/* 0x7B: JNP/JPO */ REL8()
	/* 0x7C: JL/JNGE */ REL8()
	/* 0x7D: JGE/JNL */ REL8()
	/* 0x7E: JLE/JNG */ REL8()
	/* 0x7F: JG/JNLE */ REL8()
	/* [GRP1]: 0/ADD, 1/OR, 2/ADC, 3/SBB, 4/AND, 5/SUB, 6/XOR, 7/CMP */
	/* 0x80: [GRP1] */ RM8_IMM8()
	/* 0x81: [GRP1] */ RM16_IMM16_RM32_IMM32()
	/* 0x82: ??? */ UNKNOWN()
	/* 0x83: [GRP1] */ RM16_IMM8_RM32_IMM8()
	/* 0x84: TEST */ RM8_R8()
	/* 0x85: TEST */ RM16_R16_RM32_R32()
	/* 0x86: XCHG */ RM8_R8()
	/* 0x87: XCHG */ RM16_R16_RM32_R32() /* also R16_RM16_R32_RM32() which is equivalent */
	/* 0x88: MOV */ RM8_R8()
	/* 0x89: MOV */ RM16_R16_RM32_R32()
	/* 0x8A: MOV */ R8_RM8()
	/* 0x8B: MOV */ R16_RM16_R32_RM32()
	/* 0x8C: MOV */ RM16_R16() /* Actually r/m16, Sreg */
	/* 0x8D: LEA */ R16_RM16_R32_RM32() /* Actually r16, m; or r32, m */
	/* 0x8E: MOV */ R16_RM16() /* Actually Sreg, r/m16 */
	/* 0x8F: POP */ RM16_RM32()
	/* 0x90: NOP/XCHG AX, AX */ NOP()
	/* 0x91: XCHG AX, */ CX()
	/* 0x92: XCHG AX, */ DX()
	/* 0x93: XCHG AX, */ BX()
	/* 0x94: XCHG AX, */ SP()
	/* 0x95: XCHG AX, */ BP()
	/* 0x96: XCHG AX, */ SI()
	/* 0x97: XCHG AX, */ DI()
	/* 0x98: CBW; CWDE */ NOP()
	/* 0x99: CWD; CDQ */ NOP()
	/* 0x9A: CALL FAR */ PTR16_16_PTR16_32()
	/* 0x9B: FWAIT */ NOP()
	/* 0x9C: PUSHF/PUSHFD */ NOP()
	/* 0x9D: POPF/POPFD */ NOP()
	/* 0x9E: SAHF */ NOP()
	/* 0x9F: LAHF */ NOP()
	/* 0xA0: MOV AL, moffs8 */ MOV_MOFFSET()
	/* 0xA1: MOV AX, moffs16; MOV EAX, moffs32 */ MOV_MOFFSET()
	/* 0xA2: MOV moffs8, AL */ MOV_MOFFSET()
	/* 0xA3: MOV moffs16, AX; MOV moffs32, EAX */ MOV_MOFFSET()
	/* 0xA4: MOVSB */ NOP()
	/* 0xA5: MOVSW/MOVSD */ NOP()
	/* 0xA6: CMPSB */ NOP()
	/* 0xA7: CMPSW/CMPSD */ NOP()
	/* 0xA8: TEST */ AL_IMM8()
	/* 0xA9: TEST */ AX_IMM16_EAX_IMM32()
	/* 0xAA: STOSB */ NOP()
	/* 0xAB: STOSW/STOSD */ NOP()
	/* 0xAC: LODSB */ NOP()
	/* 0xAD: LODSW/LODSD */ NOP()
	/* 0xAE: SCASB */ NOP()
	/* 0xAF: SCASW/SCASD */ NOP()
	/* 0xB0: ??? */ UNKNOWN()
	/* 0xB1: ??? */ UNKNOWN()
	/* 0xB2: ??? */ UNKNOWN()
	/* 0xB3: ??? */ UNKNOWN()
	/* 0xB4: ??? */ UNKNOWN()
	/* 0xB5: ??? */ UNKNOWN()
	/* 0xB6: ??? */ UNKNOWN()
	/* 0xB7: ??? */ UNKNOWN()
	/* 0xB8: ??? */ UNKNOWN()
	/* 0xB9: ??? */ UNKNOWN()
	/* 0xBA: ??? */ UNKNOWN()
	/* 0xBB: ??? */ UNKNOWN()
	/* 0xBC: ??? */ UNKNOWN()
	/* 0xBD: ??? */ UNKNOWN()
	/* 0xBE: ??? */ UNKNOWN()
	/* 0xBF: ??? */ UNKNOWN()
	/* [GRP2]: 0/ROL, 1/ROR, 2/RCL, 3/RCR, 4/SHL/SAL, 5/SHR, 7/SAR */
	/* 0xC0: [GRP2] */ RM8_IMM8()
	/* 0xC1: [GRP2] */ RM16_IMM8_RM32_IMM8()
	/* 0xC2: RET */ IMM16()
	/* 0xC3: RET */ NOP()
	/* 0xC4: LES */ R16_M16_16_R32_M16_32()
	/* 0xC5: LDS */ R16_M16_16_R32_M16_32()
	/* 0xC6: 0/MOV */ RM8_IMM8()
	/* 0xC7: 0/MOV */ RM16_IMM16_RM32_IMM32()
	/* 0xC8: ENTER */ IMM16_IMM8()
	/* 0xC9: LEAVE */ NOP()
	/* 0xCA: RET FAR */ IMM16()
	/* 0xCB: RET FAR */ NOP()
	/* 0xCC: INT 3 */ NOP()
	/* 0xCD: INT */ IMM8()
	/* 0xCE: INTO */ NOP()
	/* 0xCF: IRET/IRETD */ NOP()
	/* 0xD0: [GRP2] */ RM8_1()
	/* 0xD1: [GRP2] */ RM16_1_RM32_1()
	/* 0xD2: [GRP2] */ RM8_CL()
	/* 0xD3: [GRP2] */ RM16_CL_RM32_CL()
	/* 0xD4: AAM */ NOP()
	/* 0xD5: AAD */ NOP()
	/* 0xD6: ??? */ UNKNOWN()
	/* 0xD7: XLAT */ NOP()
	/* 0xD8: (x87 escape) */ UNKNOWN()
	/* 0xD9: (x87 escape) */ UNKNOWN()
	/* 0xDA: (x87 escape) */ UNKNOWN()
	/* 0xDB: (x87 escape) */ UNKNOWN()
	/* 0xDC: (x87 escape) */ UNKNOWN()
	/* 0xDD: (x87 escape) */ UNKNOWN()
	/* 0xDE: (x87 escape) */ UNKNOWN()
	/* 0xDF: (x87 escape) */ UNKNOWN()
	/* 0xE0: LOOPNE */ REL8()
	/* 0xE1: LOOPE */ REL8()
	/* 0xE2: LOOP */ REL8()
	/* 0xE3: JCXZ/JECXZ */ REL8()
	/* 0xE4: IN */ AL_IMM8()
	/* 0xE5: IN */ AX_IMM8_EAX_IMM8()
	/* 0xE6: OUT */ AL_IMM8() /* Actually imm8, AL */
	/* 0xE7: OUT */ AX_IMM8_EAX_IMM8() /* Actually imm8, ax; imm8, eax */
	/* 0xE8: CALL */ REL16_REL32()
	/* 0xE9: JMP */ REL16_REL32()
	/* 0xEA: JMP FAR */ PTR16_16_PTR16_32()
	/* 0xEB: JMP */ REL8()
	/* 0xEC: IN */ AL_DX()
	/* 0xED: IN */ AX_DX_EAX_DX()
	/* 0xEE: OUT */ AL_DX() /* Actually DX, AL */
	/* 0xEF: OUT */ AX_DX_EAX_DX() /* Actually DX, AX; DX, EAX */
	/* 0xF0: (LOCK) */ UNKNOWN()
	/* 0xF1: ??? */ UNKNOWN()
	/* 0xF2: ??? */ UNKNOWN()
	/* 0xF3: ??? */ UNKNOWN()
	/* 0xF4: HLT */ NOP()
	/* 0xF5: CMC */ NOP()
	/* [GRP3]: 0/TEST, 2/NOT, 3/NEG, 4/MUL, 5/IMUL, 6/DIV, 7/IDIV */
	/* 0xF6: [GRP3] */ RM8()
	/* 0xF7: [GRP3] */ RM16_RM32()
	/* 0xF8: CLC */ NOP()
	/* 0xF9: STC */ NOP()
	/* 0xFA: CLI */ NOP()
	/* 0xFB: STI */ NOP()
	/* 0xFC: CLD */ NOP()
	/* 0xFD: STD */ NOP()
	/* [GRP4]: 0/INC, /DEC */
	/* 0xFE: [GRP4] */ RM8()
	/* 0xFF: [GRP5]
	0: INC r/m16; INC r/m32
	1: DEC r/m16; DEC r/m32
	2: CALL r/m16; CALL r/m32
	3: CALL FAR m16:16; CALL FAR m16:32
	4: JMP r/m32; JMP r/m64
	5: JMP FAR m16:16; JMP FAR m16:32
	6: PUSH r/m16; PUSH r/m32 */ EXTENSION(5)
};

static const struct instruction_desc two_byte_inst[256] =
{
	/* 0x00: [GRP6]
	0: SLDT r/m16
	1: STR r/m16
	2: LLDT r/m16
	3: LTR r/m16
	4: VERR r/m16
	5: VERW r/m16 */ EXTENSION(6)
	/* 0x01: [GRP7]
	0: SGDT m
	1: SIDT m
	2: LGDT m16&32; LGDT m16&64
	3: LIDT m16&32; LIDT m16&64
	4: SMSW r/m16; SMSW r32/m16
	6: LMSW r/m16
	7: INVLPG */ EXTENSION(7)
	/* 0x02: LAR */ R16_RM16_R32_RM32() /* Actually r32, r32/m16 */
	/* 0x03: LSL */ R16_RM16_R32_RM32() /* Actually r32, r32/m16*/
	/* 0x04: ??? */ UNKNOWN()
	/* 0x05: SYSCALL */ NOP()
	/* 0x06: CLTS */ NOP()
	/* 0x07: SYSRET */ NOP()
	/* 0x08: INVD */ NOP()
	/* 0x09: WBINVD */ NOP()
	/* 0x0A: ??? */ UNKNOWN()
	/* 0x0B: UD2 */ UNKNOWN()
	/* 0x0C: ??? */ UNKNOWN()
	/* 0x0D: ??? */ UNKNOWN()
	/* 0x0E: ??? */ UNKNOWN()
	/* 0x0F: ??? */ UNKNOWN()
	/* 0x10: ??? */ UNKNOWN()
	/* 0x11: ??? */ UNKNOWN()
	/* 0x12: ??? */ UNKNOWN()
	/* 0x13: ??? */ UNKNOWN()
	/* 0x14: ??? */ UNKNOWN()
	/* 0x15: ??? */ UNKNOWN()
	/* 0x16: ??? */ UNKNOWN()
	/* 0x17: ??? */ UNKNOWN()
	/* 0x18: ??? */ UNKNOWN()
	/* 0x19: ??? */ UNKNOWN()
	/* 0x1A: ??? */ UNKNOWN()
	/* 0x1B: ??? */ UNKNOWN()
	/* 0x1C: ??? */ UNKNOWN()
	/* 0x1D: ??? */ UNKNOWN()
	/* 0x1E: ??? */ UNKNOWN()
	/* 0x1F: NOP */ NOP() /* TODO */
	/* 0x20: ??? */ UNKNOWN()
	/* 0x21: ??? */ UNKNOWN()
	/* 0x22: ??? */ UNKNOWN()
	/* 0x23: ??? */ UNKNOWN()
	/* 0x24: ??? */ UNKNOWN()
	/* 0x25: ??? */ UNKNOWN()
	/* 0x26: ??? */ UNKNOWN()
	/* 0x27: ??? */ UNKNOWN()
	/* 0x28: ??? */ UNKNOWN()
	/* 0x29: ??? */ UNKNOWN()
	/* 0x2A: ??? */ UNKNOWN()
	/* 0x2B: ??? */ UNKNOWN()
	/* 0x2C: ??? */ UNKNOWN()
	/* 0x2D: ??? */ UNKNOWN()
	/* 0x2E: ??? */ UNKNOWN()
	/* 0x2F: ??? */ UNKNOWN()
	/* 0x30: WRMSR */ NOP()
	/* 0x31: RDTSC */ NOP()
	/* 0x32: RDMSR */ NOP()
	/* 0x33: RDPMC */ NOP()
	/* 0x34: SYSENTER */ NOP()
	/* 0x35: SYSEXIT */ NOP()
	/* 0x36: ??? */ UNKNOWN()
	/* 0x37: ??? */ UNKNOWN()
	/* 0x38: ??? */ UNKNOWN()
	/* 0x39: ??? */ UNKNOWN()
	/* 0x3A: ??? */ UNKNOWN()
	/* 0x3B: ??? */ UNKNOWN()
	/* 0x3C: ??? */ UNKNOWN()
	/* 0x3D: ??? */ UNKNOWN()
	/* 0x3E: ??? */ UNKNOWN()
	/* 0x3F: ??? */ UNKNOWN()
	/* 0x40: CMOVO */ R16_RM16_R32_RM32()
	/* 0x41: CMOVNO */ R16_RM16_R32_RM32()
	/* 0x42: CMOVB/CMOVNAE/CMOVC */ R16_RM16_R32_RM32()
	/* 0x43: CMOVAE/CMOVNB/CMOVNC */ R16_RM16_R32_RM32()
	/* 0x44: CMOVE/CMOVZ */ R16_RM16_R32_RM32()
	/* 0x45: CMOVNE/CMOVNZ */ R16_RM16_R32_RM32()
	/* 0x46: CMOVBE/CMOVNA */ R16_RM16_R32_RM32()
	/* 0x47: CMOVA/CMOVNBE */ R16_RM16_R32_RM32()
	/* 0x48: CMOVS */ R16_RM16_R32_RM32()
	/* 0x49: CMOVNS */ R16_RM16_R32_RM32()
	/* 0x4A: CMOVP/CMOVPE */ R16_RM16_R32_RM32()
	/* 0x4B: CMOVNP/CMOVPO */ R16_RM16_R32_RM32()
	/* 0x4C: CMOVL/CMOVNGE */ R16_RM16_R32_RM32()
	/* 0x4D: CMOVGE/CMOVNL */ R16_RM16_R32_RM32()
	/* 0x4E: CMOVLE/CMOVNG */ R16_RM16_R32_RM32()
	/* 0x4F: CMOVG/CMOVNLE */ R16_RM16_R32_RM32()
	/* 0x50: ??? */ UNKNOWN()
	/* 0x51: ??? */ UNKNOWN()
	/* 0x52: ??? */ UNKNOWN()
	/* 0x53: ??? */ UNKNOWN()
	/* 0x54: ??? */ UNKNOWN()
	/* 0x55: ??? */ UNKNOWN()
	/* 0x56: ??? */ UNKNOWN()
	/* 0x57: ??? */ UNKNOWN()
	/* 0x58: ??? */ UNKNOWN()
	/* 0x59: ??? */ UNKNOWN()
	/* 0x5A: ??? */ UNKNOWN()
	/* 0x5B: ??? */ UNKNOWN()
	/* 0x5C: ??? */ UNKNOWN()
	/* 0x5D: ??? */ UNKNOWN()
	/* 0x5E: ??? */ UNKNOWN()
	/* 0x5F: ??? */ UNKNOWN()
	/* 0x60: ??? */ UNKNOWN()
	/* 0x61: ??? */ UNKNOWN()
	/* 0x62: ??? */ UNKNOWN()
	/* 0x63: ??? */ UNKNOWN()
	/* 0x64: ??? */ UNKNOWN()
	/* 0x65: ??? */ UNKNOWN()
	/* 0x66: ??? */ UNKNOWN()
	/* 0x67: ??? */ UNKNOWN()
	/* 0x68: ??? */ UNKNOWN()
	/* 0x69: ??? */ UNKNOWN()
	/* 0x6A: ??? */ UNKNOWN()
	/* 0x6B: ??? */ UNKNOWN()
	/* 0x6C: ??? */ UNKNOWN()
	/* 0x6D: ??? */ UNKNOWN()
	/* 0x6E: ??? */ UNKNOWN()
	/* 0x6F: ??? */ UNKNOWN()
	/* 0x70: ??? */ UNKNOWN()
	/* 0x71: ??? */ UNKNOWN()
	/* 0x72: ??? */ UNKNOWN()
	/* 0x73: ??? */ UNKNOWN()
	/* 0x74: ??? */ UNKNOWN()
	/* 0x75: ??? */ UNKNOWN()
	/* 0x76: ??? */ UNKNOWN()
	/* 0x77: EMMS */
	/* 0x78: ??? */ UNKNOWN()
	/* 0x79: ??? */ UNKNOWN()
	/* 0x7A: ??? */ UNKNOWN()
	/* 0x7B: ??? */ UNKNOWN()
	/* 0x7C: ??? */ UNKNOWN()
	/* 0x7D: ??? */ UNKNOWN()
	/* 0x7E: ??? */ UNKNOWN()
	/* 0x7F: ??? */ UNKNOWN()
	/* 0x80: JO */ REL16_REL32()
	/* 0x81: JNO */ REL16_REL32()
	/* 0x82: JB/JC/JNAE */ REL16_REL32()
	/* 0x83: JAE/JNB/JNC */ REL16_REL32()
	/* 0x84: JE/JZ */ REL16_REL32()
	/* 0x85: JNE/JNZ */ REL16_REL32()
	/* 0x86: JBE/JNA */ REL16_REL32()
	/* 0x87: JA/JNBE */ REL16_REL32()
	/* 0x88: JS */ REL16_REL32()
	/* 0x89: JNS */ REL16_REL32()
	/* 0x8A: JP/JPE */ REL16_REL32()
	/* 0x8B: JNP/JPO */ REL16_REL32()
	/* 0x8C: JL/JNGE */ REL16_REL32()
	/* 0x8D: JGE/JNL */ REL16_REL32()
	/* 0x8E: JLE/JNG */ REL16_REL32()
	/* 0x8F: JG/JNLE */ REL16_REL32()
	/* 0x90: SETO */ RM8()
	/* 0x91: SETNO */ RM8()
	/* 0x92: SETB/SETC/SETNAE */ RM8()
	/* 0x93: SETAE/SETNB/SETNC */ RM8()
	/* 0x94: SETE/SETZ */ RM8()
	/* 0x95: SETNE/SETNZ */ RM8()
	/* 0x96: SETBE/SETNA */ RM8()
	/* 0x97: SETA/SETNBE */ RM8()
	/* 0x98: SETS */ RM8()
	/* 0x99: SETNS */ RM8()
	/* 0x9A: SETP/SETPE */ RM8()
	/* 0x9B: SETNP/SETPO */ RM8()
	/* 0x9C: SETL/SETNGE */ RM8()
	/* 0x9D: SETGE/SETNL */ RM8()
	/* 0x9E: SETLE/SETNG */ RM8()
	/* 0x9F: SETG/SETNLE */ RM8()
	/* 0xA0: ??? */ UNKNOWN()
	/* 0xA1: ??? */ UNKNOWN()
	/* 0xA2: CPUID */
	/* 0xA3: BT */ RM16_R16_RM32_R32()
	/* 0xA4: ??? */ UNKNOWN()
	/* 0xA5: ??? */ UNKNOWN()
	/* 0xA6: ??? */ UNKNOWN()
	/* 0xA7: ??? */ UNKNOWN()
	/* 0xA8: ??? */ UNKNOWN()
	/* 0xA9: ??? */ UNKNOWN()
	/* 0xAA: RSM */ NOP()
	/* 0xAB: BTS */ RM16_R16_RM32_R32()
	/* 0xAC: ??? */ UNKNOWN()
	/* 0xAD: ??? */ UNKNOWN()
	/* 0xAE:
	3/5: LFENCE
	3/6: MFENCE
	3/7: SFENCE
	mem/4: XSAVE mem
	mem/5: XRSTOR mem
	mem/6: XSAVEOPT mem
	mem/7: CLFLUSH m8 */ EXTENSION(15)
	/* 0xAF: IMUL */ R16_RM16_R32_RM32()
	/* 0xB0: CMPXCHG */ RM8_R8()
	/* 0xB1: CMPXCHG */ RM16_R16_RM32_R32()
	/* 0xB2: LSS */ R16_M16_16_R32_M16_32()
	/* 0xB3: BTR */ RM16_R16_RM32_R32()
	/* 0xB4: LFS */ R16_M16_16_R32_M16_32()
	/* 0xB5: LGS */ R16_M16_16_R32_M16_32()
	/* 0xB6: MOVZX */ R16_RM8_R32_RM8()
	/* 0xB7: MOVZX */ R32_RM16()
	/* 0xB8: ??? */ UNKNOWN()
	/* 0xB9: ??? */ UNKNOWN()
	/* GRP8: 4/BT, 5/BTS, 6/BTR, 7/BTC */
	/* 0xBA: [GRP8] */ RM16_IMM8_RM32_IMM8()
	/* 0xBB: BTC */ RM16_R16_RM32_R32()
	/* 0xBC: BSF */ R16_RM16_R32_RM32()
	/* 0xBD: BSR */ R16_RM16_R32_RM32()
	/* 0xBE: MOVSX */ R16_RM8_R32_RM8()
	/* 0xBF: MOVSX */ R32_RM16()
	/* 0xC0: XADD */ RM8_R8()
	/* 0xC1: XADD */ RM16_R16_RM32_R32()
	/* 0xC2: ??? */ UNKNOWN()
	/* 0xC3: ??? */ UNKNOWN()
	/* 0xC4: ??? */ UNKNOWN()
	/* 0xC5: ??? */ UNKNOWN()
	/* 0xC6: ??? */ UNKNOWN()
	/* 0xC7:
	1: CMPXCHG8B m64 */ EXTENSION(9)
	/* 0xC8: BSWAP */ EAX()
	/* 0xC9: BSWAP */ ECX()
	/* 0xCA: BSWAP */ EDX()
	/* 0xCB: BSWAP */ EBX()
	/* 0xCC: BSWAP */ ESP()
	/* 0xCD: BSWAP */ EBP()
	/* 0xCE: BSWAP */ ESI()
	/* 0xCF: BSWAP */ EDI()
	/* 0xD0: ??? */ UNKNOWN()
	/* 0xD1: ??? */ UNKNOWN()
	/* 0xD2: ??? */ UNKNOWN()
	/* 0xD3: ??? */ UNKNOWN()
	/* 0xD4: ??? */ UNKNOWN()
	/* 0xD5: ??? */ UNKNOWN()
	/* 0xD6: ??? */ UNKNOWN()
	/* 0xD7: ??? */ UNKNOWN()
	/* 0xD8: ??? */ UNKNOWN()
	/* 0xD9: ??? */ UNKNOWN()
	/* 0xDA: ??? */ UNKNOWN()
	/* 0xDB: ??? */ UNKNOWN()
	/* 0xDC: ??? */ UNKNOWN()
	/* 0xDD: ??? */ UNKNOWN()
	/* 0xDE: ??? */ UNKNOWN()
	/* 0xDF: ??? */ UNKNOWN()
	/* 0xE0: ??? */ UNKNOWN()
	/* 0xE1: ??? */ UNKNOWN()
	/* 0xE2: ??? */ UNKNOWN()
	/* 0xE3: ??? */ UNKNOWN()
	/* 0xE4: ??? */ UNKNOWN()
	/* 0xE5: ??? */ UNKNOWN()
	/* 0xE6: ??? */ UNKNOWN()
	/* 0xE7: ??? */ UNKNOWN()
	/* 0xE8: ??? */ UNKNOWN()
	/* 0xE9: ??? */ UNKNOWN()
	/* 0xEA: ??? */ UNKNOWN()
	/* 0xEB: ??? */ UNKNOWN()
	/* 0xEC: ??? */ UNKNOWN()
	/* 0xED: ??? */ UNKNOWN()
	/* 0xEE: ??? */ UNKNOWN()
	/* 0xEF: ??? */ UNKNOWN()
	/* 0xF0: ??? */ UNKNOWN()
	/* 0xF1: ??? */ UNKNOWN()
	/* 0xF2: ??? */ UNKNOWN()
	/* 0xF3: ??? */ UNKNOWN()
	/* 0xF4: ??? */ UNKNOWN()
	/* 0xF5: ??? */ UNKNOWN()
	/* 0xF6: ??? */ UNKNOWN()
	/* 0xF7: ??? */ UNKNOWN()
	/* 0xF8: ??? */ UNKNOWN()
	/* 0xF9: ??? */ UNKNOWN()
	/* 0xFA: ??? */ UNKNOWN()
	/* 0xFB: ??? */ UNKNOWN()
	/* 0xFC: ??? */ UNKNOWN()
	/* 0xFD: ??? */ UNKNOWN()
	/* 0xFE: ??? */ UNKNOWN()
	/* 0xFF: ??? */ UNKNOWN()
};
