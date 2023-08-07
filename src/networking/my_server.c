/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** my_server
*/

#include <netinet/in.h>
#include "macro.h"
#include "my_socket.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int recv_and_send(int new_socket)
{
    char *buffer = NULL;
    size_t len = 0;

    getline(&buffer, &len, stdin);
    printf(">%s       by User2\n", buffer);
    send(new_socket, buffer, sizeof(buffer), 0);
    if (buffer[0] == 'o' && buffer[1] == 'u' && buffer[2] == 't') {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

int my_server(void)
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address = create_adress(PORT);
    int new_socket = 0;
    int addrlen = sizeof(address);

    if (server_fd == EXIT_FAIL) {
        perror("Socket creation failed");
        return EXIT_FAIL;
    }
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == EXIT_FAIL) {
        perror("Bind failed");
        return EXIT_FAIL;
    }
    if (listen(server_fd, 5) == EXIT_FAIL) {
        perror("Listen failed");
        return EXIT_FAIL;
    }
    printf("Server is listening on port 8080...\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket == -1) {
        perror("Accept failed");
        return (EXIT_FAIL);
    }
    while (recv_and_send(new_socket) == EXIT_SUCCESS);
    close(new_socket);
    close(server_fd);
    return EXIT_SUCCESS;
}
