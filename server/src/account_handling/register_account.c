/*
** EPITECH PROJECT, 2024
** server
** File description:
** register a user/client
*/

#include <unistd.h>
#include <stdio.h>
#include "macro.h"
#include "account.h"

int register_account(hashtable_t *ht, int client_socket, struct data_128 *user_data)
{
    char exit_code = {0};
    size_t n = 0;

    exit_code = (char)new_account(ht, user_data);
    if (exit_code != OK) {
        n = send(client_socket, &exit_code, 1, 0);
        if (n < 0)
            perror("send");
        return EXIT_FAIL;
    }
    n = send(client_socket, &exit_code, exit_code, 0);
    if (n < 0) {
        perror("send");
    }
    printf("New User : %s\n", user_data->key);
    return EXIT_SUCCESS;
}
