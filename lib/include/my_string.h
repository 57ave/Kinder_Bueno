/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my string header
*/

#ifndef MY_STRING_H
    #define MY_STRING_H

char *my_strdup_delim(char *src, char delim);

int my_strlen(char *str);

void my_perror(char *str);

int my_strcmp(char *s1, char *s2);

char **my_stwa(char *str, char *delim);

char *my_strcat_char(char *dest, char *src, char c);

#endif /* MY_STRING_H */
