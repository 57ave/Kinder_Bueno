/*
** EPITECH PROJECT, 2023
** day03
** File description:
** task07
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    long nb_l = nb;

    if (nb_l < 0) {
        write(1, "-", 1);
        nb_l = nb_l * (-1);
    }
    if (nb_l / 10) {
        my_put_nbr(nb_l / 10);
    }
    my_putchar((nb_l % 10) + '0');
    return 1;
}
