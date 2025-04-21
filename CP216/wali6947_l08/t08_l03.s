/*
-------------------------------------------------------
l08_t03.s
-------------------------------------------------------
Author: Ahmad Wali
ID: 169036947
Email: wali6947@mylaurier.ca
Date:    2024-02-21
-------------------------------------------------------
Uses a subroutine to read strings from the UART into memory.
-------------------------------------------------------
*/
.org 0x1000   // Start at memory location 1000
.text         // Code section
.global _start
_start:

bl    EchoString

_stop:
b _stop

// Subroutine constants
.equ UART_BASE, 0xff201000  // UART base address
.equ VALID, 0x8000          // Valid data in UART mask
.equ ENTER, 0x0A            // The enter key code

EchoString:
/*
-------------------------------------------------------
Echoes a string from the UART to the UART.
-------------------------------------------------------
Uses:
  r0 - holds character to print
  r1 - UART base address
  r2 - UART status register
-------------------------------------------------------
*/

    ldr r1, =UART_BASE     

EchoLoop:
    // Wait for character to be available
WaitForInput:
    ldr r2, [r1, #8]        
    tst r2, #VALID          
    beq WaitForInput       

    ldrb r0, [r1]           

    cmp r0, #ENTER         
    beq DoneEcho           

WaitToSend:
    ldr r2, [r1, #8]
    tst r2, #0x40           
    beq WaitToSend

    strb r0, [r1]           
    b EchoLoop              

DoneEcho:
    bx lr                   

.end
