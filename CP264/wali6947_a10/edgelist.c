/*
 * your program signature
 */ 

 #include <stdio.h>
 #include <stdlib.h> 
 #include "edgelist.h"
 
 EDGELIST *new_edgelist() {
     EDGELIST *tp = malloc(sizeof(EDGELIST));
     tp->size = 0;
     tp->start = NULL;
     tp->end = NULL;
     return tp;
 }
 
 void insert_edge_end(EDGELIST *g, int from, int to, int weight) {
    
    EDGENODE *newNode = (EDGENODE *)malloc(sizeof(EDGENODE));
    newNode->from = from;
    newNode->to = to;
    newNode->weight = weight;
    newNode->next = NULL;
    //if inserting into an empty graph:
    if(g->end == NULL){
        g->end = newNode;
        g->start = newNode;
    }
    else{//none empty graph:
        g->end->next=newNode;
        g->end = newNode;
    }
    g->size++;
 }
 
 void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
    //the node will have to link to the start of g
    //Allocate memory then make a new node:
    EDGENODE *newNode = (EDGENODE *)malloc(sizeof(EDGENODE));
    newNode->from = from;
    newNode->to = to;
    newNode->weight = weight;
    //Update my pointers
    newNode->next = g->start;
    g->start = newNode;
    //Edgecase
    if(g->end == NULL){
        g->end = newNode;
    }
    g->size++;
 }
 
 void delete_edge(EDGELIST *g, int from, int to) {
    if (g == NULL || g->start == NULL) return;

    EDGENODE *curr = g->start;
    EDGENODE *prev = NULL;

    while (curr) {
        if (curr->from == from && curr->to == to) {
            // Delete the node
            if (prev == NULL) {
                // Deleting the first node
                g->start = curr->next;
            } else {
                prev->next = curr->next;
            }

            if (curr == g->end) {
                // Deleting the last node
                g->end = prev;
            }

            free(curr);
            g->size--;
            return; // Only delete the first match — remove this if you want to delete all matching edges
        }

        prev = curr;
        curr = curr->next;
    }
}

 
 int weight_edgelist(EDGELIST *g) {
    if(g== NULL || g->start == NULL){
        return 0;
    }
    EDGENODE *curr = g->start;
    int weight = 0;
    while(curr != NULL){
        weight += curr->weight;
        curr = curr->next;
    }
    return weight;
 }
 
 void clean_edgelist(EDGELIST **gp) {
     EDGELIST *g = *gp;
     EDGENODE *temp, *p = g->start;
     while (p) {
         temp = p;
         p = p->next;
         free(temp);
     }
     free(g);
     *gp = NULL;
 }
 
 void display_edgelist(EDGELIST *g) {
     if (g == NULL)
         return;
     printf("size %d ", g->size);
     printf("(from to weight) ");
     EDGENODE *p = g->start;
     while (p) {
         printf("(%d %d %d) ", p->from, p->to, p->weight);
         p = p->next;
     }
 }