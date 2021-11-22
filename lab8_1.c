//
// Created by Tritean Sergiu on 22-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DM 1000
#define RANDMAX 5000
#include "greedy.c"

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

    int n, *SOL_REC = NULL, *SOL_ITER = NULL, *s = NULL, *f = NULL;
    printf_s("Introduceti lungimea sirului: \n");
    scanf_s("%d", &n);

    INIT_ARRAY(&SOL_REC, n);
    INIT_ARRAY(&SOL_ITER, n);
    INIT_ARRAY(&s, n);
    INIT_ARRAY(&f, n);

    f[0] = 0;
    int length_sol_rec = RECURSIVE_ACTIVITY_SELECTOR(s,f,0,n,SOL_REC);
    printf_s("Solutie recursiva: \n");
    PRINT_ARRAY(SOL_REC, length_sol_rec);

    int length_sol_it = GREEDY_ACTIVITY_SELECTOR(s,f,n,SOL_ITER);
    printf_s("Solutie iterativa: \n");
    PRINT_ARRAY(SOL_ITER, length_sol_it);

    free(SOL_ITER); free(SOL_REC); free(s); free(f);

    return EXIT_SUCCESS;
}