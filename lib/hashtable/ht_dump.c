/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_dump.c
*/

#include "my_string.h"
#include "hashtable.h"
#include <unistd.h>

int print_data(struct data *data_to_print)
{
    write(1, "> ", 2);
    my_put_nbr(data_to_print->hash);
    write(1, " - ", 3);
    write(1, data_to_print->value, my_strlen(data_to_print->value));
    write(1, "\n", 1);
    return 0;
}

int print_table(list_t *current_list, size_t indice)
{
    write(1, "[", 1);
    my_put_nbr(indice);
    write(1, "]:\n", 3);
    if (current_list != NULL)
        my_apply_on_nodes((void *)current_list, (int (*)(void *))&print_data);
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL) {
        return;
    }
    ht_apply(ht, &print_table);
}
