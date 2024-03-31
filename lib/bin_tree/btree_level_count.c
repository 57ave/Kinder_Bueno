/*
** EPITECH PROJECT, 2023
** day13
** File description:
** btrre_level_count.c
*/

#include "btree.h"

size_t count_level_rec(btree_t const *root, size_t max_count, size_t tmp_count)
{
    tmp_count += 1;
    if (root->left != NULL) {
        max_count = count_level_rec(root->left, max_count, tmp_count);
    }
    if (root->right != NULL) {
        max_count = count_level_rec(root->right, max_count, tmp_count);
    }
    return (max_count < tmp_count) ? tmp_count : max_count;
}

size_t btree_level_count(btree_t const *root)
{
    size_t max_count = 0;
    size_t tmp_count = 0;

    if (root == NULL) {
        return 0;
    }
    return count_level_rec(root, max_count, tmp_count);
}
