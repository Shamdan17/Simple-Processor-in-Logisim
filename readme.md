# Custom Processor
MIPS based processor designed from scratch in [Logisim](http://www.cburch.com/logisim/) as part of a Computer Architecture course at Koç University. There is also an assembler and a tool to help create machine code and memory images compatible with logisim.

## Instructions

| Instruction | Opcode | Type | Operation | Description |
|--|--|--|--|--|
|  |  |  |  |  |
add rd, rs, rt | 000000 | R | rd = rs + rt | rd = destination, rs, rt=source |
sub rd, rs, rt | 000001 | R | rd = rs - rt | rd = destination, rs, rt=source
mult rs, rt | 000010 | R | hi;lo = rs*rt | hi, lo: two 16-bit registers in multiplier unit to store 32-bit multiplication result |
and rd, rs, rt | 000011 | R | rd = rs & rt | rd = destination, rs, rt=source |
or rd, rs, rt | 000100 | R | rd = rs OR rt | rd = destination, rs, rt=source |
addi rd, rs, Imm | 000101 | I | rd = rs + Imm |  rd = destination, rs, rt=source, I = 16-bit sign extended immediate value |
sll rd, rs, shamt | 000110 | R | rd = rs << shamt| rd = destination, rs, rt=source, shamt = shift amount
slt rd, rs, rt | 000111 | R | rd = (rs < rt) | rd = 1 if rs < rt, otherwise rd = 0 |
mfhi rd | 001000 | R | rd = hi | Load hi from multiplier unit into register rd |
mflo rd | 001001 | R | rd = lo | Load lo from multiplier unit into register rd |
lw rd, i(rs) | 001010 | I |rd = rs[i] | rd = destination, rs=base address, i=offset One word refers to 2 bytes (16-bits) |
sw rs, i(rd) | 001011 | I |rd[i] = rs | rd = destination, rs,rt=source One word refers to 2 bytes (16-bits) |
beq rs, rt, label | 001100 | I |if(rs == rt) | jump to label rs, rt=registers to compare Label= offset to add to the PC Example: beq rs, rt, 16 jumps 4 instructions ahead (excluding the default instruction jump every clock cycle) if the condition is met |
blez rs, label | 001101 | I |if(rs <= 0) | jump to label  s=register to compare Label=label to jump to. Should be a number that is a multiple of 4. Example: blez rs, 16 jumps 4 instructions ahead (excluding the default instruction jump every clock cycle) if the condition is met  |
j label | 001110  | J | Jump to label | Label=label to jump to Example: j 16 jumps to the 4th instruction (0-indexed)
transfer rd, rs | 001111 | I | rd = rs | Load the contents of register rs into rd


## How to use:

To run the processor:
* Write assembly code in 32-bit MIPS style
* Run the assembler with the assembly code to get machine code
* Run the machine code to ROM image converter to get an image that's loadable and ready to use by Logisim
* Enter the contents of the memory in decimal sequentially
* Run the memory content to RAM image converter to get an image that's loadable and ready to use by Logisim
* Run the clock (manually or set logisim to tick the clock automatically)

**Note:** Registers should be referred to by numbers from 0-31

**Very important note:** When using the assembler and/or the converter, inputs should be terminated with an explicit "EOF" string, otherwise an infinite loop will occur.
