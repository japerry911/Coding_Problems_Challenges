/*
---SimpleAssemblerIntrepeter---
This is the first part of this kata series. Second part is here.

We want to create a simple interpreter of assembler which will support the following instructions:

mov x y - copies y (either a constant value or the content of a register) into register x
inc x - increases the content of the register x by one
dec x - decreases the content of the register x by one
jnz x y - jumps to an instruction y steps away (positive means forward, negative means backward, 
y can be a register or a constant), but only if x (a constant or a register) is not zero
Register names are alphabetical (letters only). Constants are always integers (positive or negative).

Note: the jnz instruction moves relative to itself. For example, an offset of -1 would continue 
at the previous instruction, while an offset of 2 would skip over the next instruction.

The function will take an input list with the sequence of the program instructions and will execute 
them. The program ends when there are no more instructions to execute, then it returns a dictionary 
with the contents of the registers.

Also, every inc/dec/jnz on a register will always be preceeded by a mov on the register first, so you 
don't need to worry about uninitialized registers.

Example
simple_assembler(['mov a 5','inc a','dec a','dec a','jnz a -1','inc a'])

''' visualized:
mov a 5
inc a
dec a
dec a
jnz a -1
inc a
''''
The above code will:

set register a to 5,
increase its value by 1,
decrease its value by 2,
then decrease its value until it is zero (jnz a -1 jumps to the previous instruction if a is not zero)
and then increase its value by 1, leaving register a at 1
So, the function should return

{'a': 1}
This kata is based on the Advent of Code 2016 - day 12
*/

function simpleAssembler(program) {
  const registers = {};
  const registerRegex = new RegExp(/[a-zA-Z]+/);
  let i = 0;

  while (i < program.length) {
    const instructionSegments = program[i].split(" ");

    if (
      registerRegex.test(instructionSegments[1]) &&
      registers[instructionSegments[1]] === undefined
    ) {
      registers[instructionSegments[1]] = 0;
    }

    if (instructionSegments[0] === "inc") {
      ++registers[instructionSegments[1]];
    } else if (instructionSegments[0] === "dec") {
      --registers[instructionSegments[1]];
    } else if (instructionSegments[0] === "mov") {
      if (registers[instructionSegments[2]] === undefined) {
        registers[instructionSegments[1]] = parseInt(instructionSegments[2]);
      } else {
        registers[instructionSegments[1]] = parseInt(
          registers[instructionSegments[2]]
        );
      }
    } else if (instructionSegments[0] === "jnz") {
      if (
        (registers[instructionSegments[1]] !== undefined &&
          registers[instructionSegments[1]] !== 0) ||
        (registers[instructionSegments[1]] === undefined &&
          instructionSegments[1] !== 0)
      ) {
        if (registers[instructionSegments[2]] === undefined) {
          i += parseInt(instructionSegments[2]);
          continue;
        } else {
          i += parseInt(registers[instructionSegments[2]]);
          continue;
        }
      }
    }

    ++i;
  }

  return registers;
}

module.exports = simpleAssembler;
