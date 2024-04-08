/*
** EPITECH PROJECT, 2024
** Kinder_Bueno
** File description:
** send method
*/

#include <unistd.h>
#include <stdio.h>
#include "macro.h"
#include "my_socket.h"
#include "account.h"
#include "my_string.h"

int send_method_handler(struct server_in *serv, char buffer[BUFFER_MAX], int client_id)
{
    struct data_128 user_data = {0};
    int socket_to_send = 0;

    my_strcpy(user_data.key, buffer);
    socket_to_send = check_connected_account(serv, &user_data);
    socket_to_send = serv->clients[socket_to_send].sock_fd;
    if (socket_to_send == EXIT_FAIL) {
        return EXIT_FAIL;
    }
    write(socket_to_send, buffer, BUFFER_MAX);
    return EXIT_SUCCESS;
}
