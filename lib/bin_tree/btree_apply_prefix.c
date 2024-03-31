/*
** EPITECH PROJECT, 2023
** btree_lib
** File description:
** apply_to_node_in_prefix
*/

#include "btree.h"
#include "stdlib.h"

void btree_apply_prefix_rec(btree_t *root, int(*applyf)(void *))
{
    if (root->left != NULL) {
        applyf(root->left->item);
        btree_apply_prefix_rec(root->left, applyf);
    }
    if (root->right != NULL) {
        applyf(root->right->item);
        btree_apply_prefix_rec(root->right, applyf);
    }
}

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    applyf(root->item);
    btree_apply_prefix_rec(root, applyf);
}
