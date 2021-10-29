//
// Created by Tritean Sergiu on 29-Oct-21.
//

#ifndef LABORATOARE_TABEL_DISPERSIE_H
#define LABORATOARE_TABEL_DISPERSIE_H

void HASH_INIT(int T[], int m);
int HASH_PRIM(int k, int m);
int HASH_PROBEF(int k, int i, int m);
int HASH_INSERT(int T[], int k, int m);
int HASH_SEARCH(int T[], int k, int m);
int HASH_DELETE( int T[], int k, int m);
void HASH_PRINT( int T[], int m);

#endif //LABORATOARE_TABEL_DISPERSIE_H
