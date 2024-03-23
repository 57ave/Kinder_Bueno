/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** my_client
*/

#include "macro.h"
#include "client.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int my_client(void)
{
    struct client_in client;

    client.addr.sin_family = AF_INET;
    client.addr.sin_port = htons(PORT);
    client.addr.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1", &(client.addr.sin_addr));
    client.addrlen = sizeof(client.addr);
    if (client.addr.sin_addr.s_addr <= 0) {
        printf("addr fail\n");
        return EXIT_FAIL;
    }
    client.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client.socket == EXIT_FAIL) {
        printf("socket failed\n");
        return EXIT_FAIL;
    }
    if (connect(client.socket, (const struct sockaddr *)&(client.addr), client.addrlen) == EXIT_FAIL) {
        printf("Connexion to server fail\n");
        return EXIT_FAIL;
    }
    char buffer[5] = {0};
    recv(client.socket, buffer, 5, 0);
    printf("hey its ok\n");
    return EXIT_SUCCESS;
}
