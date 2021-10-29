//
// Created by Tritean Sergiu on 29-Oct-21.
//

#include "tabel_dispersie.h"
#include <stdlib.h>
#include <stdio.h>

void HASH_INIT(int T[], int m) {
    for(int j=0; j<m;++j) {
        T[j] = -1;
    }
}

int HASH_PRIM(int k, int m) {
    return k % m;
}

int HASH_PROBEF(int k, int i, int m) {
    return (HASH_PRIM(k,m) + i) % m;
}

int HASH_INSERT(int T[], int k, int m) {
    int i=0;
    do {
        int j = HASH_PROBEF(k,i,m);
        if(T[j] == -1 ) {
            T[j] = k;
            return j;
        } else {
            i++;
        }
    } while(i != m );
    return -1; // tabela e plina
}

int HASH_SEARCH(int T[], int k, int m) {
    int i=0, j=0;
    do{
        j = HASH_PROBEF(k,i,m);
        if( T[j] == k ) return j;
        i++;
    } while( i != m && T[j] != -1);
    return -1; // cheie negăsită
}

int HASH_DELETE( int T[], int k, int m) {
    int j = HASH_SEARCH( T, k, m);
    if( j > -1) {
        T[j] = -1;
        return j;
    } else {
        return -1;
    }
}

void HASH_PRINT( int T[], int m) {
    for(int j=0;j<m;++j) {
        printf("%d ", T[j]);
    }
}
