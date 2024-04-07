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
    char username[128];
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
    short unsigned int size;
    char *buffer;
    char end;
};

int handle_signin(struct client_in *client, method_t method);

int handle_login(struct client_in *client, method_t method);

int send_request(struct client_in *client, char *buffer);

int get_user_info(struct data_128 *user_info, size_t n);

static const struct request_model REQ_TAB[] = {
    {CONNECT, "SIGN-IN", &handle_signin},
    {CONNECT, "LOGIN", &handle_login},
    {LAST_METHOD, NULL, NULL}
};

#endif /* !CLIENT_H_ */
