//
// Created by Tritean Sergiu on 11-Jan-22.
//

#ifndef LABORATOARE_DISJOINT_SET_H
#define LABORATOARE_DISJOINT_SET_H

void MAKE_SET(t_nod_lista *x);
t_nod_lista *x FIND_SET(t_nod_lista *x);
void LINK(t_nod_lista *x, t_nod_lista *y);
void UNION(t_nod_lista *x, t_nod_lista *y);

#endif //LABORATOARE_DISJOINT_SET_H
