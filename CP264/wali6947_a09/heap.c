/*
 * your program signature
 */ 

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h> 
 #include "heap.h"
 
 int cmp(KEYTYPE a, KEYTYPE b) {
   int r = 0;
   if (a < b) r = -1;
   else if (a > b) r = 1;
   return r;
 }
 
 HEAP *new_heap(int capacity)
 {
   HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
   if (hp == NULL) return NULL;
   hp->hda = (HEAPDATA *) malloc(sizeof(HEAPDATA) * capacity);
   if ( hp->hda == NULL) { free(hp); return NULL; };
   hp->capacity = capacity;
   hp->size = 0;
   return hp;
 }
 
 // you may add this function to be used other functions.
 int heapify_up(HEAPDATA *hda, int index) {
    int parent;
    HEAPDATA temp;
    while (index > 0) {
        parent = (index - 1) / 2;
        if (cmp(hda[index].key, hda[parent].key) < 0) {
            temp = hda[index];
            hda[index] = hda[parent];
            hda[parent] = temp;
            index = parent;
        } else {
            break;
        }
    }
    return index;
}
 
 // you may add this function to be used other functions.
 int heapify_down(HEAPDATA *hda, int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    HEAPDATA temp;

    if (left < n && cmp(hda[left].key, hda[smallest].key) < 0)
        smallest = left;

    if (right < n && cmp(hda[right].key, hda[smallest].key) < 0)
        smallest = right;

    if (smallest != index) {
        temp = hda[index];
        hda[index] = hda[smallest];
        hda[smallest] = temp;
        return heapify_down(hda, n, smallest);
    }

    return index;
}
 
void heap_insert(HEAP *heap, HEAPDATA new_node) {
    if (heap->size >= heap->capacity) return; // Full
    heap->hda[heap->size] = new_node;
    heapify_up(heap->hda, heap->size);
    heap->size++;
}
 

HEAPDATA heap_find_min(HEAP *heap) {
    return heap->hda[0]; // assume not empty
}
 
HEAPDATA heap_extract_min(HEAP *heap) {
    HEAPDATA min = heap->hda[0];
    heap->size--;
    if (heap->size > 0) {
        heap->hda[0] = heap->hda[heap->size];
        heapify_down(heap->hda, heap->size, 0);
    }
    return min;
}
 
int heap_change_key(HEAP *heap, int index, KEYTYPE new_key) {
    if (index < 0 || index >= heap->size) return 0;

    KEYTYPE old_key = heap->hda[index].key;
    heap->hda[index].key = new_key;

    if (cmp(new_key, old_key) < 0) {
        heapify_up(heap->hda, index);
    } else {
        heapify_down(heap->hda, heap->size, index);
    }
    return 1;
}
 
int heap_search_value(HEAP *heap, VALUETYPE data) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->hda[i].value == data) {
            return i;
        }
    }
    return -1;
}
 
void heap_sort(HEAPDATA *arr, int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_down(arr, n, i);
    }
    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        HEAPDATA temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify_down(arr, i, 0); // Reduce heap size each time
    }
}
 
 void heap_clean(HEAP **heapp) {
   if (heapp) {
     HEAP *heap = *heapp;
     if (heap->capacity > 0) {
       heap->capacity = 0;
       heap->size = 0;
       free(heap->hda);
       free(heap);
     }
     *heapp = NULL;
   }
 }