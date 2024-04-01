/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** client
*/

#ifndef CLIENT_H
    #define CLIENT_H
    #include <netinet/in.h>
    #include <stddef.h>
    #include "my_socket.h"

int my_client(char *ip);

struct client_in {
    int socket;
    struct sockaddr_in addr;
    socklen_t addrlen;
};

typedef enum method {
    CONNECT = 1,
    GET,
    POST,
    PATCH,
    DELETE,
    LAST_METHOD
} method_t;

struct request_model {
    method_t method;
    char *action;
    int (*pf)(struct client_in *, method_t);
};

struct request_data {
    method_t method;
    short int current_packet;
    short int total_packet;
    char buffer[BUFFER_MAX];
};

int handle_signin(struct client_in *client, method_t method);

int send_request(struct client_in *client, char *buffer);

static const struct request_model REQ_TAB[] = {
    {POST, "SIGN-IN", &handle_signin},
    {LAST_METHOD, NULL, NULL}
};

#endif /* !CLIENT_H_ */
