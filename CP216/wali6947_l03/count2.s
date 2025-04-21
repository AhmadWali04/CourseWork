/*
-------------------------------------------------------
count2.s
-------------------------------------------------------
Author:
ID:
Email:
Date:
-------------------------------------------------------
A simple count down program (bge)
-------------------------------------------------------
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

// Store data in registers
ldr r3, =COUNTER //label register 3 as the counter
mov r2, #5  // Initialize a countdown value
ldr r3, [r2]

TOP:
sub r3, r3, #1 // Decrement the countdown value
cmp r3, #0  // Compare the countdown value to 0
bge TOP   // Branch to top under certain conditions

_stop:
b _stop

.data
COUNTER:
.space 3 //space of 3 bits is enough for decimal 5 to count down
.bss

.end