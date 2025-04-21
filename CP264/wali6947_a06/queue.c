/*
 * your program signature
 */ 

 #include <stdio.h>
 #include "queue.h"
 
 /* 
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue 
 * @param NODE *np - pointer to the node.
*/
 void enqueue(QUEUE *qp, NODE *np) {
  //edge case, only node 
  if(qp->rear== NULL){
    qp->rear = np;
    qp->front = np;
  }else{
    qp->rear->next = np;
    qp->rear = np;
  }
  qp->length++;
 }  
 
 /* 
 * Dequeue and return the pointer of the removed node. 
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL 
*/
 NODE *dequeue(QUEUE *qp) {
  if(qp->front == NULL || qp->length == 0){
    printf("This is empty!");
  }
  NODE* dummy = qp->front;
  qp->front = qp->front->next;
  //if this was the only node we had then we make front/rear null
  if(qp->front == NULL){
    qp->rear == NULL;
  }
  qp->length--;
  return dummy;
 }
 

 /* 
 * Clean the linked list queue
 * @param *qp - pointer to the queue
*/
 void clean_queue(QUEUE *qp) {
   clean(&(qp->front));
   qp->front = NULL;
   qp->rear = NULL;
   qp->length=0;
 }