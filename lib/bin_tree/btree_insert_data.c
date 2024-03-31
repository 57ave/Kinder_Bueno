/*
** EPITECH PROJECT, 2023
** btree lib
** File description:
** insert class data
*/

#include "btree.h"
#include "stdlib.h"

void btree_insert_data(btree_t **root, void *item, int (*cmpf)())
{
    btree_t *tree = *root;

    if (tree == NULL) {
        *root = btree_create_node(item);
        return;
    }
    if (cmpf(tree->item, item) >= 0) {
        if (tree->right == NULL) {
            tree->right = btree_create_node(item);
            return;
        }
        tree = tree->right;
    } else {
        if (tree->left == NULL) {
            tree->left = btree_create_node(item);
            return;
        }
        tree = tree->left;
    }
    btree_insert_data(&tree, item, cmpf);
}
