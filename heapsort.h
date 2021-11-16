//
// Created by Tritean Sergiu on 16-Nov-21.
//

#ifndef LABORATOARE_HEAPSORT_H
#define LABORATOARE_HEAPSORT_H

void HEAP_SORT(int *v, int n, int *HEAP_SIZE);
void BUILD_MAX_HEAP(int *v, int n, int *HEAP_SIZE);
void MAX_HEAPIFY(int *v, int x, int *HEAP_SIZE);

int LEFT(int x);
int RIGHT(int x);

#endif //LABORATOARE_HEAPSORT_H
