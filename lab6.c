//
// Created by Tritean Sergiu on 16-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DM 1000
#include "quicksort.c"
#include "heapsort.c"
#define RANDMAX 5000

void GENERATE_RANDOM_ARRAY(int *v, int n) {
    srand(time(NULL));
    for(int i=0;i<n;++i) {
        v[i] = rand() % RANDMAX;
    }
}

void READ_ARRAY(int *v, int n ) {
    for(int i=0;i<n;++i) {
        printf_s("Introduceti elementul cu index-ul %d: ", i);
        scanf_s("%d", &v[i]);
    }
}

void PRINT_ARRAY(int *v, int n) {
    for(int i=0;i<n;++i){
        printf_s("%d ", v[i]);
    }
    printf_s("\n");
}

int main(int argc, char *argv[]) {

    int a[DM] = {0}, n, option, HEAP_SIZE = 0;
    //citeste dimensiunea sirului
    printf_s("Introduceti dimensiunea sirului: \n");
    scanf_s("%d", &n);

    GENERATE_RANDOM_ARRAY(a, n);
    printf_s("Sir generat random: \n");
    PRINT_ARRAY(a,n);

    /* Daca se aleg optiuni
    printf_s("Alegeti metoda de sortare: \n1. Quick Sort \n2. Heap Sort\n");
    scanf_s("%d", &option);

    option == 1 ? QUICK_SORT(a, 0, n-1): HEAP_SORT(a, n, &HEAP_SIZE);
    */

    printf_s("Quick sort: \n");
    QUICK_SORT(a, 0, n-1);
    PRINT_ARRAY(a, n);

    printf_s("Heap sort: \n");
    HEAP_SORT(a, n, &HEAP_SIZE);
    PRINT_ARRAY(a, n);
    return EXIT_SUCCESS;
}