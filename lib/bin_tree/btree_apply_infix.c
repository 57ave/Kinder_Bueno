/*
** EPITECH PROJECT, 2023
** btree_lib
** File description:
** apply_to_node_in_prefix
*/

#include "btree.h"
#include "stdlib.h"

void btree_apply_infix(btree_t *root, int(*applyf)(void *))
{
    if (root->left != NULL) {
        btree_apply_infix(root->left, applyf);
    }
    applyf(root->item);
    if (root->right != NULL) {
        btree_apply_infix(root->right, applyf);
    }
}
