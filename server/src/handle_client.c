/*
** EPITECH PROJECT, 2024
** my_network
** File description:
** hanlde client
*/

#include <stdio.h>
#include "my_socket.h"
#include "macro.h"

int handle_client(struct server_in *serv, char buffer[BUFFER_MAX], int client_id)
{
    int n_recv = 0;

    n_recv = recv(serv->clients[client_id].sock_fd, buffer, BUFFER_MAX, MSG_DONTWAIT);
    if (n_recv <= 1) {
        return EXIT_FAIL;
    }
    printf("send >%s\n", buffer);
    return EXIT_SUCCESS;
}
