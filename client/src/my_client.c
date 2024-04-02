/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** my_client
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include "my_string.h"
#include "macro.h"
#include "client.h"
#include "my_socket.h"

int client_loop(struct client_in *client)
{
    bool connected = true;
    char *buffer_input = NULL;
    size_t n = 0;
    char buffer_recv[SIZE_INCOME_MESS] = {0};

    recv(client->socket, buffer_recv, SIZE_INCOME_MESS, 0);
    printf("%s\n", buffer_recv);
    while (connected) {
        if (getline(&buffer_input, &n, stdin) < 0) {
            connected = false;
        }
        clean_line(buffer_input);
        send_request(client, buffer_input);
    }
    return EXIT_SUCCESS;
}

int my_client(char *ip)
{
    struct client_in client;

    client.addr.sin_family = AF_INET;
    client.addr.sin_port = htons(PORT);
    client.addrlen = sizeof(client.addr);
    if (inet_pton(AF_INET, ip, &(client.addr.sin_addr)) <= 0) {
        perror("inet_pton");
        return EXIT_FAIL;
    }
    client.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client.socket == EXIT_FAIL) {
        perror("socket");
        return EXIT_FAIL;
    }
    if (connect(client.socket, (const struct sockaddr *)&(client.addr), client.addrlen) == EXIT_FAIL) {
        perror("connect");
        return EXIT_FAIL;
    }
    printf("Hey you're in\n");
    if (client_loop(&client)) {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
