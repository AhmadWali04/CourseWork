/*
-------------------------------------------------------
l04_t02.s
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
mov    r4, #0       // Initialize count to 0
mov    r5, #0       // Initialize byte count to 0

Loop:
ldr    r0, [r2], #4 // Load value from list, increment pointer
add    r4, r4, #1   // Increment count of values
add    r5, r5, #4   // Increment byte count
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
