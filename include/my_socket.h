/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** my_socket
*/

#ifndef MY_SOCKET_H
    #define MY_SOCKET_H
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <stdbool.h>

    #define MAX_CLIENTS 5
    #define BUFFER_MAX 3000
    #define INCOME_MESS "Let's go connexion made\n"
    #define SIZE_INCOME_MESS 25

    int my_server(void);

typedef struct client {
    int sock_fd;
    bool connect;
} client_t;

struct server_in {
    int server_fd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    fd_set readfds;
    client_t clients[MAX_CLIENTS];
};

int connect_clients(struct server_in *serv);

#endif /* !MY_SOCKET_H_ */
