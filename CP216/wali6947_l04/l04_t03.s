/*
-------------------------------------------------------
l04_t03.s
-------------------------------------------------------
Author:  David Brown
ID:      123456789
Email:   dbrown@wlu.ca
Date:    2023-07-31
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

ldr    r2, =Data    // Load address of start of list
ldr    r3, =_Data   // Load address of end of list
ldr    r0, [r2], #4 // Load first value from list
mov    r6, r0       // Initialize min with first value
mov    r7, r0       // Initialize max with first value

Loop:
ldr    r0, [r2], #4 // Load next value from list, increment pointer
cmp    r0, r6       // Compare value with current min
movlt  r6, r0       // If less, update min
cmp    r0, r7       // Compare value with current max
movgt  r7, r0       // If greater, update max
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
