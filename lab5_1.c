//
// Created by Tritean Sergiu on 15-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include "insertion_sort.c"
#define DM 1000

void GENERATE_RANDOM_ARRAY(int v[DM], int n) {
    srand(time(NULL));
    for(int i=0;i<n;++i) {
        v[i] = rand();
    }
}

void READ_ARRAY(int *v, int n ) {
    for(int i=0;i<n;++i) {
        printf_s("Introduceti elementul cu index-ul %d: ", i);
        scanf_s("%d", &v[i]);
    }
}

void PRINT_ARRAY(int v[DM], int n) {
    printf_s("Sirul printat: \n");
    for(int i=0;i<n;++i){
        printf_s("%d ", v[i]);
    }
    printf_s("\n");
}

int main(int argc, char *argv[]) {

    int a[DM] = {0}, n;
    //citeste dimensiunea sirului
    printf_s("Introduceti dimensiunea sirului: \n");
    scanf_s("%d", &n);

    GENERATE_RANDOM_ARRAY(a, n);
    INSERTION_SORT(a, n);
    PRINT_ARRAY(a, n);
    return EXIT_SUCCESS;
}