//
// Created by Tritean Sergiu on 16-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DM 1000
#include "quicksort.c"
#include "heapsort.c"
#include "merge_sort.c"
#include "insertion_sort.c"

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

    READ_ARRAY(a, n);
    printf_s("Sir initial: ");
    PRINT_ARRAY(a,n);

    printf_s("Introduceti metoda de sortare:\n");
    printf_s("1 - Quick Sort\n");
    printf_s("2 - Heap Sort\n");
    printf_s("3 - Merge Sort \n");
    printf_s("4 - Insertion Sort");

    scanf_s("%d", &option);

    switch(option) {
        case 1:
            QUICK_SORT(a, 0, n-1);
            break;
        case 2:
            HEAP_SORT(a, n, &HEAP_SIZE);
            break;
        case 3:
            MERGE_SORT(a, 0, n-1);
            break;
        case 4:
            INSERTION_SORT(a, n);
            break;
        default:
            printf_s("Nu ati introdus o optiune valida");
    }

    PRINT_ARRAY(a, n);

    return EXIT_SUCCESS;
}