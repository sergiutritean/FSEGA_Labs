//
// Created by Tritean Sergiu on 28-Oct-21.
//

#include <stdio.h>
#include "stack.c"
#include <stdlib.h>

int main(int argc, char *argv[]) {

    t_stiva s;
    int key = -1;
    INIT_STACK(&s, 20);
    printf_s("Stack initialized \n");
    while( key ) {
        scanf_s("%d", &key);
        PUSH(&s, key);
        printf_s("A fost adaugata cheia %d \n", key);
        PRINT_STACK(&s);
    }
    while( !STACK_EMPTY(&s) ) {
        POP(&s);
        PRINT_STACK(&s);
    }
    FREE_STACK(&s);

    return 0;
}
