 /**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"
#include "data.c"

// Functions

queue_linked* queue_initialize() {
    queue_linked *source = malloc(sizeof *source);
    source->count = 0;
    source->front = NULL;
    source->rear = NULL;
    return source;
}

void queue_free(queue_linked **source) {
    queue_node *node = NULL;
    while((*source)->front!= NULL){
        node = (*source)->front;
        (*source)->front = (*source)->front->next;
        (*source)->count--;
        data_free(&node->item);
        free(node);
    }
    free(*source);
    *source = NULL;
    return;
}

bool queue_empty(const queue_linked *source) {
    return (source->front == NULL || source->count == 0);
}

int queue_count(const queue_linked *source) {
    return source->count;
}

bool queue_insert(queue_linked *source, data_ptr item) {
    bool inserted = false;
    queue_node *node = malloc(sizeof(*node));
    node->item = malloc(sizeof(*node->item));
    data_copy(node->item,item);
    if(source->front== NULL){
        source->rear = node;
        source->front = node;
    }else{
        source->rear->next = node;
        source->rear = node;
    }
    source->count++;
    inserted = true;
    return inserted;
}

bool queue_peek(const queue_linked *source, data_ptr item) {
    //how to compare the data_ptr items.
    if(source->front == NULL){
        return false;
    }
    else{
        return (data_compare(source->front->item,item) == 0);
    }
}

bool queue_remove(queue_linked *source, data_ptr *item) {
    bool removed = false;
    //if the top isnt the
    if(source->front!= NULL && (data_compare(source->front->item,*item) == 0)){
        *item = source->front->item;
        queue_node *temp = source->front;
        source->front = source->front->next;
        free(temp);
        removed = true;
        source->count--;
    }
    return removed;
}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;
    while(current != NULL) {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}
