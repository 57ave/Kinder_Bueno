/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** main
*/

#include <stdio.h>
#include "macro.h"
#include "client.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Wrong arguments use -h for help\n");
        return EXIT_FAIL;
    }
    if (my_client(av[1])) {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
