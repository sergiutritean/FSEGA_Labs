//
// Created by Tritean Sergiu on 29-Oct-21.
//

#ifndef LABORATOARE_HASH_H
#define LABORATOARE_HASH_H

#include "lista.c"

void INIT_HASHTABLE( t_lista T[], int m);
int HASH_FUNCTION( int k, int m);
int CHAINED_HASH_INSERT( t_lista T[], int k, int m);
void PRINT_HASHTABLE(t_lista T[], int m);
int CHAINED_HASH_SEARCH(t_lista T[], int k, int m);
int CHAINED_HASH_DELETE(t_lista T[], int k, int m);

#endif //LABORATOARE_HASH_H
