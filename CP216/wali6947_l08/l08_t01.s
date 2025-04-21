/*
-------------------------------------------------------
l08_t01.s
-------------------------------------------------------
Author: Ahmad Wali
ID: 169036947
Email: wali6947@mylaurier.ca
Date:    2024-02-21
-------------------------------------------------------
Uses a subroutine to write strings to the UART.
-------------------------------------------------------
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

ldr r4, =First
bl  WriteString
ldr r4, =Second
bl  WriteString
ldr r4, =Third
bl  WriteString
ldr r4, =Last
bl  WriteString

_stop:
b    _stop

// Subroutine constants
.equ UART_BASE, 0xff201000  // UART base address
.equ ENTER, 0x0A            // ASCII code for newline

//=======================================================
// WriteString Subroutine
//=======================================================

WriteString:
/*
-------------------------------------------------------
Writes a null-terminated string to the UART, adds ENTER.
-------------------------------------------------------
Parameters:
  r4 - address of string to print
Uses:
  r0 - holds character to print
  r1 - address of UART
  r2 - temporary for checking UART status
-------------------------------------------------------
*/
    ldr r1, =UART_BASE        

NextChar:
    ldrb r0, [r4], #1         
    cmp r0, #0                
    beq SendEnter             

WaitUART:
    ldr r2, [r1, #8]          
    tst r2, #0x40           
    beq WaitUART              

    strb r0, [r1]             
    b NextChar                

SendEnter:
    mov r0, #ENTER            

WaitUART2:
    ldr r2, [r1, #8]          
    tst r2, #0x40             
    beq WaitUART2

    strb r0, [r1]             

    bx lr                     

//=======================================================

.data
.align
// The list of strings
First:
.asciz  "First string"
Second:
.asciz  "Second string"
Third:
.asciz  "Third string"
Last:
.asciz  "Last string"
_Last:    // End of list address

.end
