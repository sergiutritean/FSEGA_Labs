//
// Created by Tritean Sergiu on 01-Nov-21.
//

#include <stdlib.h>
#include <stdio.h>
#include "arn.c"

void read_node(int *x) {
    printf_s("x = ");
    scanf_s("%d", x);
    printf_s("\n");
}

int main(int argc, char *argv[]) {

    t_rb_arbore T;
    t_rb_node *r,*n;
    int x;

    printf_s("ROOT = ");
    scanf_s("%d", &x);
    printf_s("\n");
    r = MAKE_ROOT(&T, x);

    printf_s("Introduceti x pana la citirea lui 0 \n");
    read_node(&x);

    while( x != 0 ) {
        n = CREATE_NOD(x);
        RB_INSERT(&T, n);
        read_node(&x);
    }

    printf_s("Adresa pointer left [%p] cu valoarea [%d]\n", r->left, r->left->key);
    printf_s("Adresa pointer left [%p] cu valoarea [%d]\n", r->right, r->right->key);

    printf_s("In-order walk: \n");
    INORDER_WALK(r);
    printf_s("\n");

    printf_s("Cautare nod cu cheia ");
    read_node(&x);
    n = TREE_SEARCH(r, x);
    if( n != NULL ) {
        printf_s("Nodul cu cheia %d a fost gasit", n->key);
    } else {
        printf_s("Nodul nu a fost gasit");
    }

    return EXIT_SUCCESS;
}