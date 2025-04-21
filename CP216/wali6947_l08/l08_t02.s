/*
-------------------------------------------------------
l08_t02.s
-------------------------------------------------------
Author: Ahmad Wali 
ID: 169036947
Email: wali6947@mylaurier.ca
Date:    2024-02-21
-------------------------------------------------------
Uses a subroutine to read strings from the UART into memory.
-------------------------------------------------------
*/
// Constants
.equ SIZE, 20               // Size of string buffer storage (bytes)

.org 0x1000                 // Start at memory location 1000
.text                       // Code section
.global _start
_start:

mov r5, #SIZE               // Set buffer size in r5
ldr r4, =First
bl  ReadString

mov r5, #SIZE
ldr r4, =Second
bl  ReadString

mov r5, #SIZE
ldr r4, =Third
bl  ReadString

mov r5, #SIZE
ldr r4, =Last
bl  ReadString

_stop:
b _stop

// Subroutine constants
.equ UART_BASE, 0xff201000  // UART base address
.equ ENTER, 0x0A            // The enter key code
.equ VALID, 0x8000          // Valid data in UART mask

//=======================================================
// ReadString Subroutine
//=======================================================

ReadString:
/*
-------------------------------------------------------
Reads an ENTER-terminated string from the UART.
-------------------------------------------------------
Parameters:
  r4 - address of string buffer
  r5 - size of string buffer
Uses:
  r0 - holds received character
  r1 - UART base address
  r2 - counter (number of characters read)
  r3 - UART status
-------------------------------------------------------
*/

    ldr r1, =UART_BASE      
    mov r2, #0              

ReadChar:
    // Wait for a valid character from UART
WaitForChar:
    ldr r3, [r1, #0x8]      
    tst r3, #VALID          
    beq WaitForChar         

    ldrb r0, [r1]           

    cmp r0, #ENTER          
    beq EndInput            

    cmp r2, r5              
    beq EndInput            

    strb r0, [r4], #1      
    add r2, r2, #1          
    b ReadChar              

EndInput:
    mov r0, #0             
    strb r0, [r4]           
    bx lr                   

//=======================================================

.data
.align
// The list of strings
First:
.space  SIZE
Second:
.space  SIZE
Third:
.space  SIZE
Last:
.space  SIZE
_Last:                     // End of list address

.end
