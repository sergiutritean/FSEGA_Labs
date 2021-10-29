//
// Created by Tritean Sergiu on 29-Oct-21.
//

#include <stdio.h>
#include "tabel_dispersie.c"
#define DM 1000

int main() {
    int T[DM] = {0}, m, k;
    printf_s("Introduceti dimensiunea tabelului: \n");
    scanf_s("%d", &m);

    HASH_INIT(T, m);
    printf_s("Dati numere pana la citirea lui 0 \n");

    //citim prima cheile de inserat
    scanf_s("%d", &k);
    while(k) {
        int j = HASH_INSERT(T,k,m);
        printf_s("Cheia inserata la locatia %d \n", j);
        scanf_s("%d", &k);
    }

    //printare tabela de dispersie
    HASH_PRINT(T, m);

    //cautare in tabela
    printf_s("\n");
    printf_s("Cautare cheie : ");
    scanf_s("%d", &k);
    int j = HASH_SEARCH(T, k, m);
    if( j > -1 ) {
        printf_s("Cheie găsită la locația %d\n", j);
    } else {
        printf_s("Cheia nu a fost gasita\n");
    }

    //stergere din tabela
    printf_s("\n");
    printf_s("Stergere cheie:");
    scanf_s("%d", &k);
    printf_s("\n");
    j = HASH_DELETE(T, k, m);
    if( j>-1 ) {
        printf_s("Cheie stearsa de la locatia %d\n", j);
        HASH_PRINT(T, m);
    } else {
        printf_s("Cheia nu a fost stearsa\n");
    }

}
