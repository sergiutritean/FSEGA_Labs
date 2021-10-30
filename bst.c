//
// Created by Tritean Sergiu on 30-Oct-21.
//

#include "bst.h"

t_nod_arb* MAKE_ROOT(t_arbore* A, int key ) {
    A->root = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    A->root->key = key;
    A->root->left = NULL;
    A->root->right = NULL;
    A->root->parent = NULL;
    return A->root;
}

t_nod_arb* CREATE_NODE(int key) {
    t_nod_arb* node = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void INORDER_WALK(t_nod_arb* root) {
    if( root != NULL ) {
        INORDER_WALK(root->left);
        printf_s("%d ", root->key);
        INORDER_WALK(root->right);
    }
}

void POSTORDER_WALK(t_nod_arb* root) {
    if(root != NULL) {
        POSTORDER_WALK(root->left);
        POSTORDER_WALK(root->right);
        printf_s("%d ", root->key);
    }
}

void PREORDER_WALK(t_nod_arb* root) {
    if(root != NULL) {
        printf_s("%d ", root->key);
        PREORDER_WALK(root->left);
        PREORDER_WALK(root->right);
    }
}

t_nod_arb* TREE_MIN(t_nod_arb* nod) {
    for(; nod->left != NULL; nod = nod->left);
    return nod;
}

t_nod_arb* TREE_MAX(t_nod_arb* nod) {
    for(; nod->right != NULL; nod = nod->right);
    return nod;
}

t_nod_arb* TREE_SUCCESOR(t_nod_arb* nod) {
    t_nod_arb* y = NULL;
    if( nod -> right != NULL )
        return TREE_MIN(nod->right);
    y = nod -> parent;
    while( y != NULL && nod == y->right) {
        nod = y;
        y = y->parent;
    }
    return y;
}

t_nod_arb* TREE_SEARCH(t_nod_arb* nod, int key) {
    if( nod == NULL || key == nod->key) {
        return nod;
    }
    if(key > nod->key) {
        return TREE_SEARCH(nod->right, key);
    } else {
        return TREE_SEARCH(nod->left, key);
    }
}

t_nod_arb* IT_TREE_SEARCH(t_nod_arb* nod, int key) {
    while(nod != NULL && key != nod->key) {
        nod = (key < nod->key ? nod->left : nod->right);
    }
    return nod;
}

void TREE_INSERT(t_arbore* A, t_nod_arb* nod) {
    t_nod_arb* x = A->root;
    t_nod_arb* y = NULL;
    while( x != NULL ) {
        y = x;
        x = ( nod->key < x->key ? x->left : x->right );
    }
    nod->parent = y;
    if(y == NULL ) A->root = nod;
    else if(nod->key < y->key) y->left = nod;
    else y->right = nod;
}

void TRANSPLANT(t_arbore* A, t_nod_arb* u, t_nod_arb* v) {
    if(u->parent == NULL) A->root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if(v != NULL ) v->parent = u->parent;
}

void TREE_DELETE(t_arbore* A, t_nod_arb* nod) {
    t_nod_arb* y = NULL;
    if(nod->left == NULL )
        TRANSPLANT(A, nod, nod->right);
    else if(nod->right == NULL)
        TRANSPLANT(A, nod, nod->left);
    else {
        y = TREE_MIN(nod->right);
        if( y->parent != nod ) {
            TRANSPLANT(A, y, y->right);
            y->right = nod->right;
            y->right->parent = y;
        }
        TRANSPLANT(A, nod, y);
        y->left = nod->left;
        y->left->parent = y;
    }
}