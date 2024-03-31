/*
** EPITECH PROJECT, 2023
** day13
** File description:
** apply pf level by level
*/

#include "btree.h"

void by_level_rec(btree_t *root, int level, int is_first_e,
    void (*applyf)(void *item, int level, int is_first_e))
{
    (void)root;
    (void)level;
    (void)is_first_e;
    (void)applyf;
}

void btree_apply_by_level(btree_t *root,
    void (*applyf)(void *item, int level, int is_first_e))
{
    int level = 0;
    int is_first_e = 0;

    by_level_rec(root, level, is_first_e, applyf);
}
