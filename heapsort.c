//
// Created by Tritean Sergiu on 16-Nov-21.
//

#include "heapsort.h"

void HEAP_SORT(int *v, int n, int *HEAP_SIZE) {
    BUILD_MAX_HEAP(v, n, HEAP_SIZE);
    for(int i=n-1; i>0; --i) {
        int aux = v[0]; v[0] = v[i]; v[i] = aux;
        (*HEAP_SIZE)--;
        MAX_HEAPIFY(v, 0, HEAP_SIZE);
    }
}

void BUILD_MAX_HEAP(int *v, int n, int *HEAP_SIZE) {
    *HEAP_SIZE = n-1;
    for(int i = n/2; i>=0; --i) {
        MAX_HEAPIFY(v, i, HEAP_SIZE);
    }
}

void MAX_HEAPIFY(int *v, int x, int *HEAP_SIZE) {

    int l = LEFT(x);
    int r = RIGHT(x);
    int largest;

    if(l <= *HEAP_SIZE && v[l] > v[x]) {
        largest = l;
    } else {
        largest = x;
    }

    if( r <= *HEAP_SIZE && v[r] > v[largest]) {
        largest = r;
    }

    if(largest != x) {
        int aux = v[x]; v[x] = v[largest]; v[largest] = aux;
        MAX_HEAPIFY(v, largest, HEAP_SIZE);
    }
}

int LEFT(int x) { return 2*x; }
int RIGHT(int x) { return 2*x+1; }