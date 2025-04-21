/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "bigint.h"
 
 BIGINT bigint(char *p) {
   BIGINT bn = {0};
   if (p == NULL) 
     return bn;
   else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
     return bn;
   }
   else if (*p == '0' && *(p+1) == '\0') {// just "0"
     dll_insert_end(&bn, dll_node(*p -'0'));
     return bn;
   }  
   else { 
     while (*p) {
       if (*p >= '0' && *p <= '9' ){
         dll_insert_end(&bn, dll_node(*p -'0'));
       } else {
         dll_clean(&bn);
         break;
       }
       p++;
     }
     return bn;
   }
 }
 
 BIGINT bigint_add(BIGINT op1, BIGINT op2) {
  BIGINT sum = bigint(NULL);
  NODE *p1 = op1.end;
  NODE *p2 = op2.end;
  int c = 0,a,b,s;
  while(p1||p2){
    a = 0;
    b = 0;
    if(p1){ 
      a = p1->data;
      p1 = p1->prev;
    }
    if(p2){
      b = p2->data;
      p2=p2->prev;
    }
    //computer the sum digit S and insert at the start of the doubly linked list
    s = a+b+c;
    c = s %10;
    s = s%10;

    NODE *newNode = dll_node(s + '0');
    dll_insert_start(&sum,newNode);
  }
  if(c==1){
    NODE *carryNode = dll_node('1');
    dll_insert_start(&sum,carryNode);
    //insert 1 at the end of the linked list
  }
 }
 
 BIGINT bigint_fibonacci(int n) {
  char *ch1 = "0";
  char *ch2 = "1";
  BIGINT f1 = bigint(ch1);
  BIGINT f2 = bigint(ch2);
  BIGINT temp;

  if(n==0){
    return f1;
  }
  else if (n==1){
    return f2;
  }
  else{
    for(int i = 2; i <= n;i++){
       temp = f2;
       f2 = bigint_add(f1,f2);
       //clean up the f1 value as we keep on having to add it many times over
       dll_clean(&f1);
       f1 = temp;
    }
    dll_clean(&f1);
    return f2;
  }
 }