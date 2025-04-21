/*
-------------------------------------------------------
l04_t01.s
-------------------------------------------------------
Author:  David Brown
ID:      123456789
Email:   dbrown@wlu.ca
Date:    2023-07-31
-------------------------------------------------------
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

ldr    r2, =Data    // Load address of start of list
ldr    r3, =_Data   // Load address of end of list
mov    r1, #0       // Initialize sum to 0

Loop:
ldr    r0, [r2], #4 // Load value from list, increment pointer
add    r1, r1, r0   // Add value to sum
cmp    r2, r3       // Compare current address with end of list
bne    Loop         // If not at end, continue loop

_stop:
b _stop            // Infinite loop to end program

.data
.align
Data:
.word   4,5,-9,0,3,0,8,-7,12    // The list of data
_Data: // End of list address

.end
