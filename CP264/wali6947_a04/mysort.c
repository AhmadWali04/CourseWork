#include "mysort.h"

// swap pointers
void swap(void **x, void **y) {
     void *temp = *y;
     *y = *x;
     *x = temp;
}

// a compare floating values pointed by void pointers. 
int cmp(void *x, void *y) {
   float a = *(float*)x;
   float b = *(float*)y; 
     if (a > b) return 1;
     else if (a < b) return -1;
     else return 0;
} 

/**
 * Use selection sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers.
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void select_sort(void *a[], int left, int right){
    int n = right - left + 1; // Compute actual number of elements
    //select sort goes down the whole list, tracking the minimum, and swaps it with the lowest element at the end
    //then reruns until its been through all elements

    for (int i = left; i < right; i++) {
        int k = i;
        for (int j = i + 1; j <= right; j++) {
            if (cmp(a[j], a[k]) < 0) { // Use a[j] and a[k] directly
                k = j;
            }
        }
        if (i != k) {
            swap(&a[i], &a[k]); // Pass addresses of a[i] and a[k]
        }
    }
}


/**
 * Use quick sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void quick_sort(void *a[], int left, int right) {
    if (left < right) {
        void *pivot = a[left]; 
        int i = left + 1, j = right;

        while (i <= j) {
            while (i <= right && cmp(a[i], pivot) <= 0) i++;
            while (j >= left && cmp(a[j], pivot) > 0) j--;
            if (i < j) {
                swap(&a[i], &a[j]); // Correct swapping
            }
        }
        swap(&a[left], &a[j]); // Swap pivot into correct position
        quick_sort(a, left, j - 1);
        quick_sort(a, j + 1, right);
    }
}

/**
 * Use either selection or quick sort algorithm to sort array of pointers such that their pointed values 
 * are in order defined by the given comparison function
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*)){
        if (left < right) {
        void *pivot = a[left]; 
        int i = left + 1, j = right;

        while (i <= j) {
            while (i <= right && cmp(a[i], pivot) <= 0) i++;
            while (j >= left && cmp(a[j], pivot) > 0) j--;
            if (i < j) {
                swap(&a[i], &a[j]); // Correct swapping
            }
        }
        swap(&a[left], &a[j]); // Swap pivot into correct position
        my_sort(a, left, j - 1,cmp);
        my_sort(a, j + 1, right,cmp);
    }

}