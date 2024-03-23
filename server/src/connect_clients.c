/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** connect_clients
*/

#include <sys/select.h>
#include <stddef.h>
#include <netinet/in.h>
#include <stdio.h>
#include "my_socket.h"
#include <unistd.h>
#include "macro.h"

void intialize_fdset(struct server_in *serv)
{
    FD_ZERO(&(serv->readfds));
    FD_SET(serv->server_fd, &(serv->readfds));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        serv->clients[i] = (client_t){.connect = 0, .sock_fd = 0};
    }
}

int update_clients(struct server_in *serv)
{
    int max_socket = 0;
    int socket_fd = 0;

    FD_ZERO(&(serv->readfds));
    FD_SET(serv->server_fd, &(serv->readfds));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        socket_fd = serv->clients[i].sock_fd;
        if (serv->clients->connect == true) {
            FD_SET(socket_fd, &(serv->readfds));
        }
        if (max_socket < socket_fd) {
            max_socket = socket_fd;
        }
    }
    return max_socket;
}

void find_active_client(struct server_in *serv)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients->connect == true &&
            FD_ISSET(serv->clients[i].sock_fd, &(serv->readfds))) {
            send(serv->clients[i].sock_fd, "ping\n", 5, 0);
        }
    }
}

int get_new_client(struct server_in *serv)
{
    int new_socket = 0;

    if (FD_ISSET(serv->server_fd, &(serv->readfds))) {
        printf("new client detected\n");
        new_socket = accept(serv->server_fd, (struct sockaddr *)&(serv->addr), (socklen_t *)&(serv->addrlen));
        if (new_socket < 0) {
            printf("tmr\n");
            return -1;
        }
        FD_SET(new_socket, &(serv->readfds));
        if (send(new_socket, INCOME_MESS, SIZE_INCOME_MESS, 0) != SIZE_INCOME_MESS) {
            perror("send");
        }
        write(new_socket, "fuck\n", 5);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (serv->clients[i].connect == false) {
                serv->clients[i].sock_fd = new_socket;
                break;
            }
        }
    }
    return 0;
}

int connect_clients(struct server_in *serv)
{
    int max_socket = 0;

    intialize_fdset(serv);
    while (1) {
        max_socket = update_clients(serv);
        if (select(max_socket + 1, &(serv->readfds), NULL, NULL, NULL) == EXIT_FAIL) {
            printf("select fail\n");
            return EXIT_FAIL;
        }
        get_new_client(serv);
        find_active_client(serv);
    }
}
