//
// Created by Tritean Sergiu on 12-Dec-21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista_adiacenta.c"

int main(int argc, char *argv[]) {
    t_lista* G[DM];
    t_lista* topology;
    int s, n1, n2;

    printf_s("Nr noduri = ");
    scanf_s("%d", &n);

    INIT_LISTA_AD(&G);
    for(int i=1;i<=n;++i) {
        INSERT_VECINI(G, i);
    }

    printf_s("Lista adiacenta: ");
    PRINT_LISTA(G);

    printf_s("Parcurgere in latime:\n");
    printf_s("Nod start: ");
    scanf_s("%d", &s);

    BFS(G, G[s]->head);

    printf_s("Calea cea mai scurta:\n");
    printf_s("Nod start: ");
    scanf_s("%d", &n1);
    printf_s("Nod Finish: ");
    scanf_s("%d", &n2);

    PRINT_PATH(G, G[n1]->head, G[n2]->head);

    printf_s("Parcurgere in adancime\n");
    DFS(G);

    printf_s("Sortare topologica\n");
    topology = TOP_SORT(G);
    LIST_PRINT(topology);

    return EXIT_SUCCESS;
}