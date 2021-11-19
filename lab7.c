//
// Created by Tritean Sergiu on 19-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DM 1000
#include "dp.c"
#define RANDMAX 5000

void READ_ARRAY(int *v, int n ) {
    for(int i=0;i<n;++i) {
        printf_s("Introduceti elementul cu index-ul %d: ", i);
        scanf_s("%d", &v[i]);
    }
}

int main(int argc, char *argv[]) {

    int n, maxValue;
    printf_s("Introduceti lungimea sirului: \n");
    scanf_s("%d", &n);

    int *a = (int*)malloc(sizeof(int)*(n+1));
    READ_PRICES(a, n);

    maxValue = CUT_ROD(a, n);
    printf_s("Valoare maxima recursiva: %d\n", maxValue);

    maxValue = MEMOIZED_CUT_ROD_AUX(a, n);
    printf_s("Valoare maxima top-down: %d\n", maxValue);

    maxValue = BOTTOM_UP_CUT_ROD(a, n);
    printf_s("Valoare maxima bottom-up: %d\n", maxValue);

    return EXIT_SUCCESS;
}