/*
** EPITECH PROJECT, 2023
** btree lib
** File description:
** create_btree
*/

#include "btree.h"
#include <stdlib.h>

void btree_create(btree_t **root, char *left_arg, char *right_arg)
{
    btree_t *btree = *root;

    if (left_arg != NULL) {
        btree->left = btree_create_node(left_arg);
    } else {
        return;
    }
    if (right_arg != NULL) {
        btree->right = btree_create_node(right_arg);
    } else {
        return;
    }
}
