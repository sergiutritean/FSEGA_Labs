//
// Created by Tritean Sergiu on 28-Oct-21.
//

#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

void INIT_STACK(t_stiva *s, int init_size) {
    s->data = (int*)malloc(sizeof(int)*init_size);
    s->top = 0;
};

void FREE_STACK(t_stiva *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
}

bool STACK_EMPTY(t_stiva *s) {
    return s->top == 0;
}

void PUSH(t_stiva *s, int elem ) {
    //if(!s.top) s.top = 0;
    s->data[++(s->top)] = elem;
}

void PRINT_STACK(t_stiva *s) {
    printf_s("%d\n", s->top);
    for(int i=1; i<s->top; ++i)
        printf_s("%d ", s->data[i]);
    printf_s("\n");
}

int POP(t_stiva *s) {
    if(STACK_EMPTY(s)) {
        printf_s("Stiva e goala! \n");
        return -1;
    }
    int elem = s->data[s->top];
    s->data[s->top--] = 0;
    return elem;
}
