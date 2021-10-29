//
// Created by Tritean Sergiu on 29-Oct-21.
//

#include <stdlib.h>
#include <stdio.h>
#include "hash.c"
#define DM 1000
int main(int argc, char *argv[]) {
    t_lista T[DM];
    int m,k;

    printf_s("Functia de dispersie h(k) = k mod m \n");
    printf_s("Introduceti dimensiunea tabelei:");
    scanf_s("%d", &m);
    INIT_HASHTABLE(T, m);

    //introducerea numerelor in hash
    printf_s("Dati numere pana la citirea lui 0: \n");
    scanf_s("%d", &k);
    while(k) {
        int j = CHAINED_HASH_INSERT(T,k,m);
        printf_s("Am adaugat elementul %d\n", k);
        printf_s("Tabela actualizata:\n");
        PRINT_HASHTABLE(T,m);
        scanf_s("%d", &k);
    }

    //cautare cheie
    printf_s("Inserati cheie de cautat: \n");
    scanf_s("%d", &k);
    int j = CHAINED_HASH_SEARCH(T,k,m);
    if( j > -1 ){
        printf_s("Cheie gasita la locatia %d \n", j);
    } else {
        printf_s("Cheia nu a fost gasita \n");
    }

    //stergere cheie
    printf_s("Cheia pentru stergere: ");
    scanf_s("%d", &k);
    j = CHAINED_HASH_DELETE(T, k, m);
    if( j>-1 ) {
        printf_s("Cheie stearsa la locatia %d \n", j);
        PRINT_HASHTABLE(T, m);
    } else {
        printf_s("Cheia nu a fost gasita");
    }
}