/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

int name_set_free(name_set **set) {
    //program takes a pointer to a pointer as a parameter
    if(set == NULL || *set == NULL){
        return 0;
    }
    int n = 1;
    name_set_node *curr = (*set)->front;
    //point to the front of the linked list
    while(curr != NULL){
        name_set_node *temp = curr;
        curr = curr->next;
        free(temp);
        n++;
    }
    return n;
}

BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {
    //if nameset contains returns a 0, then lets add it
    if(set->front == NULL){
        name_set_node *newNode = malloc(sizeof(name_set_node));
        strcpy(newNode->first_name,first_name);
        strcpy(newNode->last_name, last_name);
        newNode->next = NULL;
        newNode = set->front;
        newNode = set->rear;
    }
    if(name_set_contains(set,first_name,last_name) == 0){
        //create the new node by first allocating memory space for it, add your elements then update pointers
        name_set_node *newNode = malloc(sizeof(name_set_node));
        strcpy(newNode->first_name,first_name);
        strcpy(newNode->last_name, last_name);
        newNode->next = NULL;
        set->rear->next = newNode;
        newNode = set->rear;
        return TRUE;
    }
    //handle edgacse for when dealing with an empty set
    return FALSE;

}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) {
    //check for if we have the same name in our set already, if we dont then we pass off
    if (set == NULL){
        return FALSE;
    }
    name_set_node *curr = set->front;
    while(curr != NULL){
        //check if we found a match, and return
        if((strcmp(curr->first_name,first_name) == 0) && (strcmp(curr->last_name,last_name) ==0)){
            return TRUE;
        }
        curr = curr->next;
    }
    return FALSE;
}

void name_set_print(const name_set *set) {
    name_set_node *curr = set->front;
    while(curr != NULL){
        printf("%s, %s\n",curr->last_name,curr->first_name);
        curr = curr->next;
    }
}
