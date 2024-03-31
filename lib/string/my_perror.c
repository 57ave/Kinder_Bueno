/*
** EPITECH PROJECT, 2024
** libc
** File description:
** my_perror
*/

#include <stddef.h>
#include "my_string.h"
#include "unistd.h"

void my_perror(char *str)
{
    size_t size = my_strlen(str);

    write(2, str, size);
}
