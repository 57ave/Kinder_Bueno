/*
** EPITECH PROJECT, 2023
** day07
** File description:
** strcat
*/

#include "my_string.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len = my_strlen(dest);
    int i = 0;

    if (n < 0) {
        n *= -1;
    } else if (n == 0) {
        return dest;
    }
    for (; src[i] != '\0' && i < n; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
