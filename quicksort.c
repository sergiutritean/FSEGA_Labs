//
// Created by Tritean Sergiu on 16-Nov-21.
//

#include "quicksort.h"

void QUICK_SORT( int *v, int p, int r) {
    int q = 0;
    if(p < r ) {
        q = PARTITION(v, p, r);
        QUICK_SORT(v, p, q-1);
        QUICK_SORT(v, q+1, r);
    }
}

int PARTITION( int *v, int p, int r) {
    int x = v[r];
    int i = p-1;

    for(int j = p; j<r; ++j) {
        if(v[j] <= x) {
            i++;
            int aux = v[i]; v[i] = v[j]; v[j] = aux;
        }
    }

    v[r] = v[i+1];
    v[i+1] = x;

    return i+1;
}