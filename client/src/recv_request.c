/*
** EPITECH PROJECT, 2024
** Kinder_Bueno
** File description:
** recv_request
*/

#include <stdio.h>
#include <unistd.h>
#include "macro.h"
#include "client.h"

int handle_data(struct client_in *client, char buffer[BUFFER_MAX])
{
    write(1, "Recv from : ", 10);
    write(1, buffer, 128);
    write(1, "\n> ", 3);
    write(1, &buffer[128], BUFFER_MAX);
    write(1, "\n", 1);
}

int recv_request(struct client_in *client)
{
    size_t n = 0;
    char buffer[BUFFER_MAX] = {0};

    n = recv(client->socket, buffer, BUFFER_MAX, MSG_DONTWAIT);
    if (n <= 0) {
        return EXIT_FAIL;
    }
    if (buffer[0] != '\0') {
        handle_data(client, buffer);
    }
    return EXIT_SUCCESS;
}
