/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** main
*/

#include "macro.h"
#include "client.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    if (my_client()) {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
