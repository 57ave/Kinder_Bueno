/*
** EPITECH PROJECT, 2023
** btree_lib
** File description:
** create_node
*/

#include "btree.h"
#include "stdlib.h"

btree_t *btree_create_node(void *item)
{
    btree_t *btree = malloc(sizeof(*btree));

    btree->item = item;
    btree->left = NULL;
    btree->right = NULL;
    return btree;
}
