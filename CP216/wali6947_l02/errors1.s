/*
-------------------------------------------------------
errors1.s
-------------------------------------------------------
Author:Ahmad Wali
ID:169036947
Email: wali6947@mylaurier.ca
Date: 2025-01-29
-------------------------------------------------------
Assign to and add contents of registers.
-------------------------------------------------------
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

// Copy data from memory to registers
ldr r3, =A  //copy the address of A into register 3
ldr r0, [r3] //copies the contents of A into regsiter 0
ldr r3, =B // copies the address of B into register 3 
ldr r1, [r3] //copies the contents of B into register 1

add r2, r1, r0 

// Copy data to memory
ldr r3, =Result // Assign address of Result to r3
str r2, [r3] // Store contents of r2 to address in r3
// End program
_stop:
b _stop

.data      // Initialized data section
A:
.word 4
B:
.word 8
.bss     // Uninitialized data section
Result:
.space 4 // Set aside 4 bytes for result

.end