/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** my_server
*/

#include <netinet/in.h>
#include <arpa/inet.h>
#include "macro.h"
#include "my_socket.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sys/time.h"

int recv_and_send(int new_socket)
{
    char *buffer = NULL;
    size_t len = 0;

    getline(&buffer, &len, stdin);
    printf(">client send: %s\n", buffer);
    send(new_socket, buffer, sizeof(buffer), 0);
    if (buffer[0] == 'o' && buffer[1] == 'u' && buffer[2] == 't') {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

int my_server(void)
{
    struct server_in serv;

    serv.server_fd = socket(AF_INET, SOCK_STREAM, 0);
    serv.addr.sin_family = AF_INET;
    serv.addr.sin_port = htons(PORT);
    serv.addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    serv.addrlen = sizeof(struct sockaddr_in);
    if (serv.server_fd == EXIT_FAIL) {
        perror("Socket creation failed");
        return EXIT_FAIL;
    }
    if (bind(serv.server_fd, (const struct sockaddr *)&(serv.addr), serv.addrlen)) {
        perror("Bind failed");
        return EXIT_FAIL;
    }
    if (listen(serv.server_fd, 5) == EXIT_FAIL) {
        perror("Listen failed");
        return EXIT_FAIL;
    }
    printf("Server is listening on port 8080...\n");
    if (connect_clients(&serv)) {
        close(serv.server_fd);
        return EXIT_FAIL;
    }
    close(serv.server_fd);
    return EXIT_SUCCESS;
}
