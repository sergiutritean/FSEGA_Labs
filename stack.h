//
// Created by Tritean Sergiu on 28-Oct-21.
//

#ifndef LABORATOARE_STACK_H
#define LABORATOARE_STACK_H

#include <stdbool.h>

typedef struct stack {
    int top;
    int *data;
}t_stiva;

void INIT_STACK(t_stiva *s, int init_size);

void FREE_STACK(t_stiva *s);

bool STACK_EMPTY(t_stiva *s);

void PUSH(t_stiva *s, int elem );

void PRINT_STACK(t_stiva *s);

int POP(t_stiva *s);

#endif //LABORATOARE_STACK_H
