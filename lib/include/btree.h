/*
** EPITECH PROJECT, 2023
** binary_tree_lib
** File description:
** btrre.h
*/

#ifndef BTREE_H_
    #define BTREE_H_
    #include <stddef.h>
typedef struct btree {
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;

btree_t *btree_create_node(void *item);

void btree_apply_prefix(btree_t *root, int (*applyf)(void *));

void btree_apply_infix(btree_t *root, int (*applyf)(void *));

void btree_apply_suffix(btree_t *root, int (*applyf)(void *));

void btree_create(btree_t **root, char *left, char *right);

void btree_insert_data(btree_t **root, void *item, int (*cmp)());

void *btree_search_item(btree_t *root, void const *data_ref, int (*cmp)());

size_t btree_level_count(btree_t const *root);

void btree_apply_by_level(btree_t *,
    void (*applyf)(void *item, int level, int is_first_elem));

#endif
