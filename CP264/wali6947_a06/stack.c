/*
 * your program signature
 */ 
#include <stdio.h>
#include "stack.h"
#include "common.h"

/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/ 
void push(STACK *sp, NODE *np) {
    np->next = sp->top;
    sp->top = np;
    sp->length++;
}

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL  
*/ 
NODE *pop(STACK *sp) {
  if(sp->top == NULL || sp->length == 0){
    printf("The top is empty!");
  }
  NODE* dummy = sp->top;
  sp->top = sp->top->next;
  dummy->next = NULL;
  sp->length--;
  return dummy;
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}