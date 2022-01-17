//
// Created by Tritean Sergiu on 11-Jan-22.
//

#include "disjoint_set.h"
#include "lista.h"

void MAKE_SET(t_nod_lista *x) {
    x -> prev = x;
    x -> rank = 0;
}

t_nod_lista *x FIND_SET(t_nod_lista *x) {
    if( x != x->prev )
        x->prev = FIND_SET(x->prev);

    return x->prev;
}

void LINK(t_nod_lista *x, t_nod_lista *y) {
    if( x->rank > y->rank )
        y->prev = x;
    else {
        y -> prev = x;
        if ( x->rank == y->rank)
            x->rank ++;
    }
}

void UNION(t_nod_lista *x, t_nod_lista *y) {
    LINK(FIND_SET(x), FIND_SET(y));
}