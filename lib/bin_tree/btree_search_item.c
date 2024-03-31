/*
** EPITECH PROJECT, 2023
** btree_lib
** File description:
** apply_to_node_in_prefix
*/

#include "btree.h"
#include "stdlib.h"

void *btree_search_item(btree_t *root, void const *data_ref, int(*cmp)())
{
    void *item = NULL;

    if (root->left != NULL) {
        if (cmp(root->left->item, data_ref) == 0) {
            return root->left->item;
        }
        item = btree_search_item(root->left, data_ref, cmp);
    }
    if (cmp(root->item, data_ref) == 0) {
        return root->item;
    }
    if (root->right != NULL) {
        if (cmp(root->right->item) == 0) {
            return root->right->item;
        }
        item = btree_search_item(root->right, data_ref, cmp);
    }
    return item;
}
