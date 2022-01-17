//
// Created by Tritean Sergiu on 12-Dec-21.
//

#include "lista_adiacenta.h"
//#include "lista.c"

int timp = 0;
int n = 0;

t_nod_lista* INIT_NODE() {
    t_nod_lista* nod = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    nod->next = NULL;
    nod->prev = NULL;
    return nod;
}

void MAKENULL( t_lista *lista) {
    lista->head = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    lista->head->prev = NULL;
    lista->head->next = NULL;
}

t_nod_lista* FIND_NODE(t_lista* G[], int v) {
    for(int i=1;i<DM;++i) {
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u->cheie == v)
                return u;
        }
    }
    return NULL;
}

void ENQUEUE(t_nod_lista* Q[], int *q, t_nod_lista* nod) {
    Q[++(*q)] = nod;
}

t_nod_lista* DEQUEUE(t_nod_lista *Q[], int *q) {
    t_nod_lista* retr = Q[1];
    for(int i=1; i<=(*q);++i) {
        Q[i] = Q[i+1];
    }
    (*q)--;
    return retr;
}

void BFS ( t_lista* G[], t_nod_lista *s) {

    t_nod_lista* Q[100];
    int q = -1;

    for(int i=1;i<=n;++i) {
        if( G[i] == NULL ) {
            continue;
        }
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if (u != s) {
                u->color = white;
                u->d = INF;
                u->prev = NULL;
            }
        }
    }

    s->color = gray;
    s->d = 0;
    s->prev = NULL;

    printf_s("%d ", s->cheie);

    MARK_VISITED( G, s->cheie);
    ENQUEUE( Q, &q, s);

    while ( q ) {
        t_nod_lista* u = DEQUEUE (Q, &q);
        for(t_nod_lista *v = G[u->cheie]->head; v != NULL; v = v->next) {
            if( v->color == white ) {
                v->color = gray;
                v->d = u->d + 1;
                v->prev = u;
                printf_s("%d\n", v->cheie);

                t_nod_lista* h = G[v->cheie]->head;
                h->prev = u;
                h->d = u->d + 1;
                MARK_VISITED(G, v->cheie);
                ENQUEUE(Q, &q, v);
            }
        }
    }
}

void MARK_VISITED(t_lista* G[], int key) {
    for(int i=1;i<=n;++i) {
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u -> cheie == key) {
                u->color = gray;
            }
        }
    }
}

void INIT_LISTA_AD(t_lista* G[]) {
    printf_s("am intrat\n");
    for(int i=1;i<DM;++i) {
        printf_s("%d \n", i);
        MAKENULL(&G[i]);
    }
}

void INSERT_VECINI(t_lista* G[], int s) {

    printf_s("Nod sursa %d:\n", s);
    G[s]->head = INIT_NODE();
    G[s]->head->cheie = s;

    printf_s("Dati vecinii nodului sursa: \n");

    int v;
    do {
        printf_s("Vecin cu %d\n", s);
        scanf_s("%d", &v);
        if(v > 0 && v<=DM && v!=s) {
            t_nod_lista *nod = INIT_NODE();
            nod->cheie = v;
            LIST_INSERT(G[s], nod);
        }
    } while( v > 0 );
}

void LIST_INSERT( t_lista *lista, t_nod_lista *nod) {
    if(lista->head == NULL) {
        lista->head = nod;
        return;
    }

    t_nod_lista* tip = lista->head;
    for(;tip->next != NULL; tip = tip->next);
    tip->next = nod;
    nod->prev = tip;
}

void PRINT_LISTA(t_lista* G[]) {
    t_nod_lista *nod = NULL;
    for(int i=1;i<=n;++i) {
        nod = G[i]->head;
        printf_s("%d: ",i);
        for(;nod != NULL; nod = nod->next) {
            printf_s("%d ", nod->cheie);
        }
        printf_s("\n");
    }
}

void PRINT_PATH(t_lista* G[], t_nod_lista *s, t_nod_lista *v) {
    if(v == s) {
        printf_s("%d ", s->cheie);
    } else if(v->prev == NULL) {
        printf_s("Nu exista cale\n");
    } else {
        PRINT_PATH(G, s, v->prev);
        printf_s("%d ", v->cheie);
    }
}

void DFS_VISIT(t_lista* G[], t_nod_lista *u) {
    timp++;
    u->d = timp;
    u->color = gray;
    printf_s("%d ", u->cheie);
    MARK_VISITED(G, u->cheie);
    for(t_nod_lista *v = G[u->cheie]->head->next; v != NULL; v = v->next) {
        if(v->color == white) {
            v->prev = u;
            DFS_VISIT(G, v);
        }
    }
    u->color = black;
    timp++;
    u->f = timp;
}

void DFS(t_lista* G[]) {
    for(int i=1; i<=n; ++i) {
        for(t_nod_lista *v = G[i]->head; v!= NULL; v = v->next) {
            v->color = white;
            v->prev = NULL;
        }
    }
    timp = 0;
    for(int i=1; i<=n; ++i) {
        if( G[i]->head->color == white ){
            DFS_VISIT(G, G[i]->head);
        }
    }
}

void DFS_VISIT_TOP(t_lista* G[], int u, t_lista *topo) {
    timp ++;
    G[u]->head->d = timp;
    G[u]->head->color = gray;
    MARK_VISITED(G, u);
    for(t_nod_lista *v = G[u]->head; v != NULL; v = v->next) {
        if(v->color == white) {
            v->prev = G[u]->head;
            DFS_VISIT_TOP(G, v->cheie, topo);
        }
    }
    G[u]->head->color = black;
    timp++;
    G[u]->head->f = timp;
    LIST_INSERT(topo, u);
}

t_lista* TOP_SORT(t_lista* G[]) {
    t_lista* topology;
    MAKENULL(topology);
    for(int i=1;i<=n; ++i) {
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u->color == white) {
                DFS_VISIT_TOP(G, u->cheie, topology);
            }
        }
    }
    return topology;
}

void LIST_PRINT( t_lista *lista) {
    for(t_nod_lista *nod = lista->head; nod != NULL; nod = nod->next) {
        printf_s("%d ", nod->cheie);
    };
    printf_s("\n");
}