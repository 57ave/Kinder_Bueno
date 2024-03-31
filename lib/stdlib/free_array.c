/*
** EPITECH PROJECT, 2024
** lib
** File description:
** free array
*/

#include <stddef.h>
#include <stdlib.h>

void free_array(void **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
