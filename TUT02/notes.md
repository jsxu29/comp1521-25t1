## MIPS
- assembly language used to program the MIPS microprocessor 
- assembly language: human-readable representation of a computer's machine code
- essentially the bridge between the machine and something like C++

Fun fact: you will be using mipsy to compile and run MIPS programs in this course. Mipsy is a MIPS32 emulator, written by someone from UNSW, that simplifies some of the instructions.

## Debugging
- mipsy-interactive (1521 mipsy)
- mipsy-web (https://cs1521.web.cse.unsw.edu.au/mipsy/)
- Printf (syscall) debugging

## Registers
- look at docs

## Writing Code

### Sections
- .text means run this code
- .data means place this in memory
By default, assembly starts in .text.
If you place your .data first, make sure you place .text somewhere after it.

### Instructions
- each instruction is 32-bits
- load/store 
- arithmetic 
- branch (b instruction uses relative addressing, j uses absolute, generally in smaller programs use b and larger programs use j)
- syscalls
