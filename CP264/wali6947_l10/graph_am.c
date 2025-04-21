/**
 * -------------------------------------
 * @file  graph_am.c
 * Adjacency Matrix Graph Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "graph_am.h"
#include <stdbool.h>

// Initializes an adjacency matrix graph.
graph_am* graph_am_initialize(int size) {
    graph_am *source = malloc(sizeof *source);
    source->size = size;
    // Initialize values to zeroes.
    source->values = calloc(size * size, sizeof *source->values);
    return source;
}

void graph_am_free(graph_am **source) {
    // Free up the data array.
    free((*source)->values);
    (*source)->values = NULL;
    free(*source);
    *source = NULL;
    return;
}

int graph_am_add_vertice(graph_am *source, const graph_am_pair *pair) {
    //bad cases where we have either a null graph, or imprpoper dimensions
    if(source == NULL || pair == NULL)return 0;
    if(pair->row < 0 || pair->row>= source->size) return 0;
    if(pair->col < 0 || pair->col>= source->size) return 0;
    //row * size jumps to the correct row, size + col jumps to the right column
    int *base = source->values + pair->row * source->size + pair->col;
    int *mirror = source->values + pair->col * source->size + pair->row;

    if(pair->row == pair->col){                    //if were jumping to ourself (looping connection)
        if(*base != 0)return 0;                    //if its already filled we dont add to it
        *(base) = 2;                               //otherweise we add 2 
    } else{
        if(*base!= 0) return 0;         //if were not jumping to ourselves and its already 1 leave it
        *base = 1;                      //otherwise add 1 to both its spot and its symmetric spot
        *mirror = 1;
    }
    return 1;
}


int graph_am_remove_vertice(graph_am *source, const graph_am_pair *pair){
    if(source==NULL || pair== NULL) return 0;
    if(pair->row < 0 || pair->row >=source->size)return 0;
    if(pair->col < 0 || pair->col >= source->size) return 0;
    int *base = source->values + pair->row * source->size + pair->col;
    int *mirror = source->values + pair->col * source->size + pair->row;

    if(pair->row == pair->col){
        if(*base == 1) return -1;
        *(base) = 0;
    }else{
        if(*base ==0) return 0;
        *base = -1;
        *mirror = -1;
    }
    return -1;
}

graph_am* graph_am_create(int size, const graph_am_pair pairs[], int count) {
    graph_am *source = graph_am_initialize(size);
    if ((source) == NULL) return NULL;
    for(int i = 0; i<count;i++){
        graph_am_add_vertice(source, &pairs[i]); //we pass the source and then we pass the address to the pairs list
        }
    return source;
}


void graph_am_neighbours(const graph_am *source, int vertex, int vertices[], int *count) {
    if (source == NULL || vertex < 0 || vertex >= source->size) {
        *count = 0;
        return;
    }

    int size = source->size;
    *count = 0;

    for (int i = 0; i < size; i++) {
        int value = source->values[vertex * size + i];
        if (value > 0) {
            vertices[(*count)++] = i;
        }
    }
}


int graph_am_degree(const graph_am *source, int vertex) {
    int connected = 0;
    if(source == NULL || vertex < 0 || vertex>=source->size){
        return 0;
    }
    for(int col = 0; col< source->size; col++){
        int value = source->values[vertex * source->size + col];
        connected += value;
    }
    return connected;
}

void graph_am_breadth_traversal(const graph_am *source, int vertex, int vertices[], int *count) {
    if (source == NULL || vertex < 0 || vertex >= source->size || vertices == NULL || count == NULL) {
        if (count != NULL) *count = 0;
        return;
    }

    int size = source->size;

    // Defensive allocation checks
    bool *visited = calloc(size, sizeof(bool));
    int *queue = malloc(size * sizeof(int));
    if (visited == NULL || queue == NULL) {
        free(visited);
        free(queue);
        *count = 0;
        return;
    }

    int front = 0, rear = 0;
    visited[vertex] = true;
    queue[rear++] = vertex;
    *count = 0;

    while (front < rear) {
        int current = queue[front++];

        // Safety check: prevent buffer overflow on vertices[]
        if (*count >= size) break;
        vertices[(*count)++] = current;

        for (int i = 0; i < size; i++) {
            int value = source->values[current * size + i];
            if (value > 0 && !visited[i]) {
                visited[i] = true;

                // Safety check: prevent buffer overflow on queue[]
                if (rear < size) {
                    queue[rear++] = i;
                }
            }
        }
    }

    free(visited);
    free(queue);
}


void graph_am_depth_traversal(const graph_am *source, int vertex, int vertices[], int *count) {
    if (source == NULL || vertex < 0 || vertex >= source->size) {
        *count = 0;
        return;
    }

    int size = source->size;
    bool *visited = calloc(size, sizeof(bool));
    int *stack = malloc(size * sizeof(int));
    int top = -1;

    *count = 0;
    stack[++top] = vertex;

    while (top >= 0) {
        int current = stack[top--];

        if (!visited[current]) {
            visited[current] = true;
            vertices[(*count)++] = current;

            // Push neighbors in reverse order so lowest index is visited first
            for (int i = size - 1; i >= 0; i--) {
                int value = source->values[current * size + i];
                if (value > 0 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }

    free(visited);
    free(stack);
}


// Prints the contents of an adjacency matrix graph.
void graph_am_print(const graph_am *source) {
    // Print the column numbers.
    printf("    ");

    for(int i = 0; i < source->size; i++)
        printf("%3d", i);
    printf("\n");
    printf("    ");
    for(int i = 0; i < source->size; i++)
        printf("---");
    printf("\n");

    // Print the row numbers and rows.
    for(int i = 0; i < source->size; i++) {
        printf("%3d|", i);

        for(int j = 0; j < source->size; j++) {
            // find item using offsets
            printf("%3d", *(source->values + i * source->size + j));
        }
        printf("\n");
    }
}
