/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** client
*/

#ifndef CLIENT_H
    #define CLIENT_H
    #include <netinet/in.h>

int my_client(void);

struct client_in {
    int socket;
    struct sockaddr_in addr;
    socklen_t addrlen;
};

#endif /* !CLIENT_H_ */
