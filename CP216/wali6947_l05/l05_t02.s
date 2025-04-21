/*
-------------------------------------------------------
l05_t02.s
-------------------------------------------------------
Author: Ahmad Wali
ID: 169036947
Email: wali6947@mylaurier.ca
Date:    2024-02-21
-------------------------------------------------------
Calculates stats on an integer list.
-------------------------------------------------------
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

mov    r1, #0       // Initialize counters
mov    r2, #0
mov    r3, #0
ldr    r4, =Data    // Store address of start of list
ldr    r5, =_Data   // Store address of end of list
bl     list_stats   // Call subroutine - total returned in r0

_stop:
b      _stop

//-------------------------------------------------------
list_stats:
/*
-------------------------------------------------------
Counts number of positive, negative, and 0 values in a list.
Equivalent of: void stats(*start, *end, *zero, *positive, *negatives)
-------------------------------------------------------
Parameters:
  r1 - number of zero values
  r2 - number of positive values
  r3 - number of negative values
  r4 - start address of list
  r5 - end address of list
Uses:
  r0 - temporary value
-------------------------------------------------------
*/
stmfd   sp!, {r0,r4-r5}
Loop:
//cmompare them against r0, and branch to branch greater than, branch less than, branch eqal
ldr r0, [r4], #4
cmp r0, #0
TestNegative:
bge TestPositive
ADD r3, r3, #1
bal Next
TestPositive:
beq TestZero
ADD r2, r2, #1
bal Next
TestZero:
ADD r1, r1, #1

Next:
cmp r4,r5
BNE Loop
ldmfd   sp!, {r0,r4-r5}
bx lr

.data
.align
Data:
.word   4,5,-9,0,3,0,8,-7,12    // The list of data
_Data: // End of list address

.end