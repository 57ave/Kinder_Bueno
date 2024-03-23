/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** main
*/

#include "macro.h"
#include "my_socket.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    if (my_server() != EXIT_SUCCESS) {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
