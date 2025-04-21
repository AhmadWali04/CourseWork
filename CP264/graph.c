/*
 * your program signature
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue_stack.h"
#include "graph.h"

GRAPH *new_graph(int order) {
  GRAPH *gp = malloc(sizeof(GRAPH));
  gp->nodes = malloc(order * sizeof(GNODE*));
  
  int i;
  for (i = 0; i < order; i++) {
    gp->nodes[i] = malloc(sizeof(GNODE));
    gp->nodes[i]->nid = i;
    strcpy(gp->nodes[i]->name, "null");
    gp->nodes[i]->neighbor = NULL;
  }
  
  gp->order = order;
  gp->size = 0;  
 
  return gp;
}


/*
incorrect version:
void insert_edge_graph(GRAPH *g, int from, int to, int weight) {
  /edge cases: null graph, or invalid from/to
  if(!g || from < 0 || from > g->order || to < 0 || to >g->order) return;
  else{
  /case: we already have the node in the graph then update its weight
  /Pointers to the current node and its edge 
  GNODE (*fromNode) = g->nodes[from];  
  ADJNODE (*curr) = fromNode->neighbor;
  /if we have it in our graph, start from current and keep going til the end if we find it updatae weight
  while(curr){
    if(curr->nid == to){
      curr->weight = weight;
    }
    curr = curr->next;
  }
  /GNODE is a vertex on the graph and ADJNODE is is their edge.
  /GNODE is like a city and ADJNODE is a road connecting them
  ADJNODE *newNode = (ADJNODE *)malloc(sizeof(ADJNODE));
  newNode->nid=to;
  newNode->weight = weight;
  newNode->next = fromNode->neighbor;
  fromNode->neighbor = newNode;
  g->size++;
  }
}

*/
void insert_edge_graph(GRAPH *g, int from, int to, int weight) {
  // Validate graph and node indices
  if (!g || from < 0 || from >= g->order || to < 0 || to >= g->order) return;

  GNODE *from_node = g->nodes[from];
  ADJNODE *curr = from_node->neighbor;
  ADJNODE *prev = NULL;

  // Traverse to find insertion point or existing edge
  while (curr != NULL && curr->nid < to) {
      prev = curr;
      curr = curr->next;
  }

  // If edge to 'to' already exists, update weight and return
  if (curr != NULL && curr->nid == to) {
      curr->weight = weight;
      return;
  }

  // Otherwise, create a new edge node
  ADJNODE *new_node = (ADJNODE *)malloc(sizeof(ADJNODE));
  if (!new_node) {
      fprintf(stderr, "Memory allocation failed.\n");
      return;
  }
  new_node->nid = to;
  new_node->weight = weight;
  new_node->next = curr;

  // Insert at head or between prev and curr
  if (prev == NULL) {
      from_node->neighbor = new_node;  // Insert at start
  } else {
      prev->next = new_node;  // Insert between
  }

  g->size++;  // Increment edge count
}

void delete_edge_graph(GRAPH *g, int from, int to) {
  //basically we can create an edge looping through it and then deleting it
  if(!g || from < 0|| from > g->order || to < 0 || to > g->order) return;

  GNODE *fromNode = g->nodes[from];
  ADJNODE *curr = fromNode->neighbor;
  ADJNODE *prev = NULL;
  while(curr){
    //if we found the node to delete
    if(curr->nid = to){
      //if its at the front
      if(!prev){
        fromNode->neighbor = curr->next;
      } else{
        prev->next = curr->next;
      }
      free(curr);
      g->size--;
      return;
    }
    prev = curr;
    curr=curr->next;
  }
  //this looks very same to removing from a linked list just gotta understand what were using ADJNODE and GNODE for
}

int get_edge_weight(GRAPH *g, int from, int to){
  if(!g || from < 0|| from > g->order || to < 0 || to > g->order) return INFINITY;

  GNODE *fromNode = g->nodes[from];
  ADJNODE *curr = fromNode->neighbor;
  while(curr){
    if(curr->nid == to){
      return curr->weight;
    }
    curr = curr->next;
  }
  return INFINITY;
}

void traverse_bforder(GRAPH *g, int nid) {
  if (!g || nid < 0 || nid >= g->order) return;

  bool *visited = (bool *)calloc(g->order, sizeof(bool));
  if (!visited) {
      printf("Memory allocation failed.\n");
      return;
  }

  QUEUE q = { NULL, NULL };  // initialize queue

  int *start = malloc(sizeof(int));
  *start = nid;
  enqueue(&q, start);
  visited[nid] = true;

  while (q.front != NULL) {
      int *curr = (int *)dequeue(&q);
      int id = *curr;
      free(curr);

      printf("(%d %s) ", id, g->nodes[id]->name);

      ADJNODE *neighbor = g->nodes[id]->neighbor;
      while (neighbor) {
          if (!visited[neighbor->nid]) {
              int *next_id = malloc(sizeof(int));
              *next_id = neighbor->nid;
              enqueue(&q, next_id);
              visited[neighbor->nid] = true;
          }
          neighbor = neighbor->next;
      }
  }

  printf("\n");
  clean_queue(&q);
  free(visited);
}

void traverse_dforder(GRAPH *g, int start) {
  if (!g || start < 0 || start >= g->order) return;

  bool *visited = (bool *)calloc(g->order, sizeof(bool));
  if (!visited) {
      printf("Memory allocation failed.\n");
      return;
  }

  STACK stack = { NULL };

  int *s = malloc(sizeof(int));
  *s = start;
  push(&stack, s);

  while (stack.top != NULL) {
      int *curr = (int *)pop(&stack);
      int curr_id = *curr;
      free(curr);

      if (!visited[curr_id]) {
          visited[curr_id] = true;
          printf("(%d %s) ", curr_id, g->nodes[curr_id]->name);

          // Count how many neighbors are unvisited
          int count = 0;
          ADJNODE *p = g->nodes[curr_id]->neighbor;
          while (p) {
              if (!visited[p->nid]) count++;
              p = p->next;
          }

          // Store unvisited neighbors in a temp array
          int **temp = malloc(count * sizeof(int *));
          p = g->nodes[curr_id]->neighbor;
          int i = 0;
          while (p) {
              if (!visited[p->nid]) {
                  temp[i] = malloc(sizeof(int));
                  *temp[i] = p->nid;
                  i++;
              }
              p = p->next;
          }

          // Push neighbors in reverse order
          for (int j = i - 1; j >= 0; j--) {
              push(&stack, temp[j]);
          }

          free(temp);
      }
  }

  printf("\n");
  clean_stack(&stack);
  free(visited);
}



void clean_graph(GRAPH **gp) {
  int i;
  GRAPH *g = *gp;
  ADJNODE *temp, *ptr;
  for (i = 0; i < g->order; i++) {
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    free(g->nodes[i]);
  }
  free(g->nodes);
  free(g);
  *gp = NULL;
}

void display_graph(GRAPH *g) {
  if (g ) {
  printf("order %d ", g->order);
  printf("size %d ", g->size);
  printf("(from to weight) ");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    //printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d %d) ", i,  ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
  }
}
