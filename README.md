# Assembly-Co-Processor-and-Simulator
The project involves implementing a functional simulator for Assembly instructions integrated with a RISC-V Architecture. 
•Basic arithmetic, logical and memory operations are supported in a pipelined design with support for caches.
The overall project will have two phases which will eventually bring out such a simulator.
Phase 1: Conversion of Assembly code to Machine code.
Here, we are doing the job of a 16bit RISC-V assembler. Program will take a .asm file as input and generate a .mc file.
Phase 2: Code for a 5 step instruction execution.
Design and implement the function simulator 16bit RISCV ISA instructions.
Here, we would take the input from the .mc file (output of Phase 1) and pick one instruction
at a time, using the value in PC (0x0). Include structures for all the registers here - PC, IR, Register File,
temporary registers (like RM, RY, etc), etc., five steps of instruction execution as functions.
All the instructions in the given in the input .mc file is executed as per the functional
behavior of the instructions. Each instruction will go through the following steps:
Step 1: Fetch
Step 2: Decode
Step 3: Execute
Step 4: Memory Access
Step 5: Register Update or Writeback
Along with execution of instruction in steps, simulator will also provide messages
what it is doing in each stage as an update in all the structures that would change. As part
of the simulator, you should implement an additional instruction which exits the simulator,
writes the data memory in .mc file before exiting. Further, It introduce a variable “clock”
that increments once for every instruction. Print the number of clock cycles at the end of
each cycle.
