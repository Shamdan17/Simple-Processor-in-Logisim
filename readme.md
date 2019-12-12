# Custom Processor
MIPS based processor

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


## How to use:

To run the processor:
* Write assembly code  in 32-bit MIPS style
* Run the assembler with the assembly code to get machine code
* Run the machine code to ROM image converter to get an image that's loadable and ready to use by Logisim

**Note:** Registers should be referred to by numbers from 0-31
 
