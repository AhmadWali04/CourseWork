/*
 * your program signature
 */ 

 #include <stdio.h>
 #include <stdlib.h> 
 #include <string.h>
 #include "hash.h"
 
 HNODE *hashtable_search(HASHTABLE *ht, char *name) {
    int index = hash(name, ht->size);
    HNODE *curr = ht->hna[index];

    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;  // Not found
}
 
 int hashtable_insert(HASHTABLE *ht, DATA data) {
    if (hashtable_search(ht, data.name) != NULL) {
        return 0;  // Already exists
    }

    int index = hash(data.name, ht->size);

    HNODE *new_node = (HNODE*)malloc(sizeof(HNODE));
    if (new_node == NULL) {
        return 0;  // Memory allocation failed
    }

    new_node->data = data;
    new_node->next = ht->hna[index];
    ht->hna[index] = new_node;
    ht->count++;

    return 1;  // Success 
}
 
int hashtable_delete(HASHTABLE *ht, char *name) {
    if (ht == NULL || name == NULL) return 0;
    int index = hash(name, ht->size);
    HNODE *curr = ht->hna[index];
    HNODE *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0) {
            if (prev == NULL) {
                // Node is at the head of the list
                ht->hna[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            ht->count--;
            return 1; // Deleted successfully
        }
        prev = curr;
        curr = curr->next;
    }

    return 0; // Not found
}

 
 
 int hash(char* key, int size) {
     unsigned int hash = 0;
     while (*key) {
         hash += *key++;
     }
     return hash % size;
 }
 
 HASHTABLE *new_hashtable(int size) {
     HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
     ht->hna = (HNODE**) malloc(sizeof(HNODE**) * size);
     int i;
     for (i = 0; i < size; i++)
         *(ht->hna + i) = NULL;
 
     ht->size = size;
     ht->count = 0;
     return ht;
 }
 
 
 void hashtable_clean(HASHTABLE **htp) {
     if (*htp == NULL)
         return;
     HASHTABLE *ht = *htp;
     HNODE *p, *temp;
     int i;
     for (i = 0; i < ht->size; i++) {
         p = ht->hna[i];
         while (p) {
             temp = p;
             p = p->next;
             free(temp);
         }
         ht->hna[i] = NULL;
     }
     free(ht->hna);
     ht->hna = NULL;
     *htp = NULL;
 }
 