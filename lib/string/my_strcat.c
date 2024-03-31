/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_strcat
*/

#include "my_string.h"
#include <stdlib.h>

char *my_strcat_char(char *dest, char *src, char c)
{
    int len_src = my_strlen(src);
    int len_dest = my_strlen(dest);
    int i_dest = 0;
    int i_src = 0;
    char *content = malloc(sizeof(char) * (len_src + len_dest + 2));

    while (dest[i_dest] != '\0') {
        content[i_dest] = dest[i_dest];
        i_dest++;
    }
    content[i_dest] = c;
    i_dest++;
    for (; src[i_src] != '\0'; i_src++) {
        content[i_dest] = src[i_src];
        i_dest++;
    }
    content[i_dest] = '\0';
    return content;
}
