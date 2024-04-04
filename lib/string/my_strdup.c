/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my_string.h"

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    if (new_str == NULL) {
        return NULL;
    }
    for (; str[i] != '\0'; i++) {
        new_str[i] = str[i];
    }
    new_str[i] = '\0';
    return new_str;
}
