/*
** EPITECH PROJECT, 2023
** day11
** File description:
** my_list.h
*/

#ifndef MY_LIST_H
    #define MY_LIST_H

typedef struct list {
    void *data;
    struct list *next;
} list_t;

int my_list_size(list_t const *begin);

int my_put_node(list_t **list, void *data);

int my_apply_on_nodes(list_t *begin, int (*pf)(void *));

list_t *my_find_node(list_t *begin,
    void const *data_ref, int (*cmp)());

void add_node(list_t *list, void *data);

int my_delete_nodes(list_t **begin, void const *data_ref, int (*cmp)());

#endif /* MY_LIST_H */
