/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** protocol
*/

#pragma once

    #include "client.h"

struct method_handler {
    method_t method;
    int (*handler)(struct server_in *, char [BUFFER_MAX], int);
};

int connect_method_handler(struct server_in *, char buffer[BUFFER_MAX], int);

static const struct method_handler METHOD_HANDLE[] = {
    {CONNECT, &connect_method_handler},
    {LAST_METHOD, NULL}
};
