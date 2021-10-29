//
// Created by Tritean Sergiu on 29-Oct-21.
//

#ifndef LABORATOARE_QUEUE_H
#define LABORATOARE_QUEUE_H

#include <stdbool.h>

typedef struct queue {
    int *data;
    int head, tail, length, capacity;
} t_queue;

void INIT_QUEUE(t_queue* Q, int init_size);
void FREE_QUEUE(t_queue* Q);
void ENQUEUE(t_queue* Q, int elem);
int DEQUEUE(t_queue* Q);
void PRINT_QUEUE(t_queue* Q);
bool QUEUE_EMPTY(t_queue* Q);

#endif //LABORATOARE_QUEUE_H
