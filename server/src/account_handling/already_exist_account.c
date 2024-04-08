/*
** EPITECH PROJECT, 2024
** server
** File description:
** register a user/client
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "macro.h"
#include "my_socket.h"
#include "account.h"
#include "my_string.h"

int check_connected_account(struct server_in *serv, struct data_128 *data)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (my_strcmp(data->key, serv->clients[i].username) == 0) {
            return i;
        }
    }
    return EXIT_FAIL;
}

int already_connected_account(int client_socket)
{
    char exit_code = ALREADY_CONNECTED;
    size_t n = 0;

    n = send(client_socket, &exit_code, exit_code, 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
