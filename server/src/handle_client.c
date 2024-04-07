/*
** EPITECH PROJECT, 2024
** my_network
** File description:
** hanlde client
*/

#include <stdio.h>
#include "my_socket.h"
#include "macro.h"
#include "my_string.h"
#include "my_unistd.h"
#include "account.h"
#include "protocol.h"

int connect_method_handler(struct server_in *serv, char buffer[BUFFER_MAX], int client_id)
{
    struct data_128 user_data = {0};
    size_t n_recv = recv(
        serv->clients[client_id].sock_fd, &user_data, sizeof(struct data_128), 0);
    int return_value = 0;

    if (n_recv < 0) {
        perror("recv");
        return EXIT_FAIL;
    }
    if (check_connected_account(serv, &user_data) == EXIT_SUCCESS)
        return already_connected_account(serv->clients[client_id].sock_fd);
    if (my_strcmp("SIGN-IN", buffer) == 0) {
        return_value = register_account(serv->ht, serv->clients[client_id].sock_fd, &user_data);
        if (return_value == EXIT_SUCCESS)
            my_strcpy(serv->clients[client_id].username, user_data.key);
        return return_value;
    }
    if (my_strcmp("LOGIN", buffer) == 0) {
        return_value = login_account(serv->ht, serv->clients[client_id].sock_fd, &user_data);
        if (return_value == EXIT_SUCCESS)
            my_strcpy(serv->clients[client_id].username, user_data.key);
        return return_value;
    }
    return EXIT_FAIL;
}

static int find_method(struct server_in *serv, char buffer[BUFFER_MAX], int client_id)
{
    for (int i = 0; METHOD_HANDLE[i].method != LAST_METHOD; i++) {
        if (METHOD_HANDLE[i].method == *buffer) {
            return METHOD_HANDLE[i].handler(serv, &buffer[1], client_id);
        }
    }
    return EXIT_FAIL;
}

int handle_client_request(struct server_in *serv, char buffer[BUFFER_MAX], int client_id)
{
    int n_recv = 0;

    n_recv = recv(serv->clients[client_id].sock_fd, buffer, BUFFER_MAX, MSG_DONTWAIT);
    if (n_recv <= 1) {
        return EXIT_FAIL;
    }
    if (find_method(serv, buffer, client_id) == EXIT_FAIL) {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
