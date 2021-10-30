//
// Created by Tritean Sergiu on 30-Oct-21.
//

#include <stdlib.h>
#include <stdio.h>
#include "bst.c"
#define DM 1000

void read_node(int *x) {
    printf_s("x = ");
    scanf_s("%d", x);
    printf_s("\n");
}

int main(int argc, char *argv[]) {
    t_arbore T;
    t_nod_arb* n = NULL;
    t_nod_arb* r = NULL;
    t_nod_arb* s = NULL;
    int x;

    //creare rădăcină
    printf_s("Nodul sau radacina cu cheia x = ");
    scanf_s("%d", &x);
    printf_s("\n");
    r = MAKE_ROOT(&T, x);

    //inserare noduri
    printf_s("Introduceți x pana la citirea lui 0 \n");
    read_node(&x);
    while (x) {
        n = CREATE_NODE(x);
        TREE_INSERT(&T, n);
        read_node(&x);
    }

    printf_s("IN-order walk: \n");
    INORDER_WALK(r);
    printf_s("\n");

    printf_s("Pre-order walk: \n");
    PREORDER_WALK(r);
    printf_s("\n");

    printf_s("Post-order walk: \n");
    POSTORDER_WALK(r);
    printf_s("\n");

    //cautare nod iterativ
    printf_s("Regasire nod cu cheia x = ");
    scanf_s("%d", &x);
    n = IT_TREE_SEARCH(r, x);
    if( n != NULL ) {
        printf_s("Nodul cu cheia %d gasit iterativ \n", n->key);
    } else {
        printf_s("Nodul nu a fost gasit iterativ \n");
    }

    //cautare nod recursiv
    n = TREE_SEARCH(r, x);
    if( n != NULL ) {
        printf_s("Nodul cu cheia %d a fost gasit recursiv \n", n->key);
    } else {
        printf_s("Nodul cu cheia %d nu a fost gasit recursiv \n", n->key);
    }

    //gasire minim
    n = TREE_MIN(r);
    printf_s("Tree minimum: %d \n", n->key);

    //gasire maxim
    n = TREE_MAX(r);
    printf_s("Tree maximum: %d \n", n->key);

    //afisare succesor
    printf_s("Succesorul lui ");
    read_node(&x);
    n = IT_TREE_SEARCH(r, x);
    s = TREE_SUCCESOR(n);
    if( s != NULL ) {
        printf_s("Nod succesor: %d \n", s->key);
    } else {
        printf_s("NULL \n");
    }

    //stergere nod
    printf_s("Stergere nod cu cheia ");
    read_node(&x);
    n = TREE_SEARCH(r, x);
    if( n != NULL ) {
        TREE_DELETE(&T, n);
        printf_s("Nodul a fost sters \n");
        INORDER_WALK(r);
    } else {
        printf_s("Nod negăsit! \n");
    }

    return EXIT_SUCCESS;
}