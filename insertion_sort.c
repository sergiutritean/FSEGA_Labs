//
// Created by Tritean Sergiu on 15-Nov-21.
//

#include "insertion_sort.h"

void INSERTION_SORT(int *v, int n) {
    int i, key, j;
    for(j=1;j<n;++j) {
        key = v[j];
        i = j-1;
        while(i>=0 && v[i] > key ) {
            v[i+1] = v[i];
            i--;
        }
        v[++i] = key;
    }
}
