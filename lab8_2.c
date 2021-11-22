//
// Created by Tritean Sergiu on 22-Nov-21.
//

//
// Created by Tritean Sergiu on 22-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DM 1000
#define RANDMAX 5000
#include "dame.c"

void PRINT_ARRAY(int *v, int n) {
    for(int i=0;i<n;++i){
        printf_s("%d ", v[i]);
    }
    printf_s("\n");
}

void READ_ARRAY(int *v, int n ) {
    for(int i=0;i<n;++i) {
        printf_s("Introduceti elementul cu index-ul %d: ", i);
        scanf_s("%d", &v[i]);
    }
}

void INIT_ARRAY(int **v, int n) {
    *v = (int*)malloc(sizeof(int)*(n+1));
}

int main(int argc, char *argv[]) {

    int n, nr_sol = 0, *x = NULL;

    printf_s("Introduceti lungimea sirului: \n");
    scanf_s("%d", &n);

    INIT_ARRAY(&x, n);

    x[3]++;
    DAME(x, n, &nr_sol);

    printf_s("Numar solutii: %d", nr_sol);

    return EXIT_SUCCESS;
}