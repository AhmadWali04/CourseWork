/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "myrecord_sllist.h"
 
 
 NODE *sll_search(SLL *sllp, char *name) {
    NODE *r = NULL, *np = sllp->start;
    while (np!=NULL){
        if(strcmp(np->data.name,name)==0){
            return np;
        }
        else{
            np = np->next;
        }
    }
    return r;
 }
 
 void sll_insert(SLL *sllp, char *name, float score) {
    //creates the node and our varaibles
    NODE *np = (NODE*)malloc(sizeof(NODE));
    strcpy(np->data.name,name);
    np->data.score = score;
    np->next = NULL;
    sllp->length++;
    NODE *prev = NULL, *current = sllp->start;
    while(current!=NULL && (current->data.score < score)){
        prev = current;
        current = current->next;
    }if(prev == NULL){//empty linked list edge case
        sllp->start=np;
        np->next=current;
    }else{//insert where we must
        prev->next = np;
        np->next =current;
    }
    
 }
 
 int sll_delete(SLL *sllp, char *name) {
    NODE *prev = NULL, *current = sllp->start;
    while(current!=NULL){
        //printf("Node: %s vs Parameter: %s \n", current->data.name,name);
        if(strcmp((current->data.name),name) == 0){
            if(prev == NULL){
                sllp->start=current->next;
            }else{
                prev->next=current->next;
            }
            free(current);
            sllp->length--;
            return 1;
        }
        prev=current;
        current = current->next;
    }
    return 0;
 }
 
 void sll_clean(SLL *sllp) {
     NODE *temp, *ptr = sllp->start;
     while (ptr != NULL) {
         temp = ptr;
         ptr = ptr->next;
         free(temp);
     }
     sllp->start = NULL;
     sllp->length = 0;
 }