/*
-------------------------------------------------------
file name
description
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947@mylaurier.ca
Date:    2025-01-21
-------------------------------------------------------
*/
.org    0x1000  // Start at memory location 1000
.text           // Code section
.global _start
_start:

mov r0, #9       // Store decimal 9 in register r0
mov r1, #14   // Store hex E (decimal 14) in register r1
add r2, r1, r0  // Add the contents of r0 and r1 and put result in r2
mov r5, #5
add r4, r5, #4
// End program
_stop:
b   _stop

.end