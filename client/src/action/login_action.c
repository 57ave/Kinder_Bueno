/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** sign action
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_socket.h"
#include "macro.h"
#include "stdbool.h"
#include "my_unistd.h"
#include "my_string.h"
#include "client.h"
#include "account.h"

static int handle_response(struct client_in *client, struct data_128 *user_info)
{
    char exit_code = {0};
    int n = recv(client->socket, &exit_code, 1, 0);

    if (n < 0) {
        perror("recv");
        return EXIT_FAIL;
    }
    if (exit_code != OK) {
        if (exit_code == FAIL)
            printf("Fail to sign\n");
        return EXIT_FAIL;
    }
    my_strcpy(client->username, user_info->key);
    printf("Successfully connected\n");
    return EXIT_SUCCESS;
}

int handle_login(struct client_in *client, method_t method)
{
    char buffer[BUFFER_MAX] = {0};
    size_t n = 0;
    struct data_128 user_info = {0};

    if (client->username[0] != 0) {
        printf("already connected\n");
        return EXIT_SUCCESS;
    }
    if (get_user_info(&user_info, n) == EXIT_FAIL) {
        return EXIT_FAIL;
    }
    printf("\nUsername : %s\nPassword : %s\n", user_info.key, user_info.value);
    buffer[0] = (char)method;
    my_strncat(buffer, "SIGN-IN", 7);
    send(client->socket, buffer, BUFFER_MAX, 0);
    send(client->socket, &user_info, sizeof(struct data_128), 0);
    if (handle_response(client, &user_info))
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}
