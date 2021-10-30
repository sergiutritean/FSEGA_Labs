//
// Created by Tritean Sergiu on 30-Oct-21.
//

#ifndef LABORATOARE_BST_H
#define LABORATOARE_BST_H

typedef struct nod_arb {
    int key;
    struct nod_arb *left, *right, *parent;
} t_nod_arb;

typedef struct {
    t_nod_arb *root;
} t_arbore;

t_nod_arb* MAKE_ROOT(t_arbore* A, int key );

t_nod_arb* CREATE_NODE(int key);

void INORDER_WALK(t_nod_arb* root);

void POSTORDER_WALK(t_nod_arb* root);

void PREORDER_WALK(t_nod_arb* root);

t_nod_arb* TREE_MIN(t_nod_arb* nod);

t_nod_arb* TREE_MAX(t_nod_arb* nod);

t_nod_arb* TREE_SUCCESOR(t_nod_arb* nod);

t_nod_arb* TREE_SEARCH(t_nod_arb* nod, int key);

t_nod_arb* IT_TREE_SEARCH(t_nod_arb* nod, int key);

void TREE_INSERT(t_arbore* A, t_nod_arb* nod);

void TRANSPLANT(t_arbore* A, t_nod_arb* u, t_nod_arb* v);

void TREE_DELETE(t_arbore* A, t_nod_arb* nod);
#endif //LABORATOARE_BST_H
