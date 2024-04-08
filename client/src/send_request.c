/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** client request handling
*/

#include <stdio.h>
#include "client.h"
#include "my_string.h"
#include "macro.h"

int send_request(struct client_in *client, char *buffer)
{
    int exit_status = 0;

    if (buffer == NULL) {
        return EXIT_SUCCESS;
    }
    clean_line(buffer);
    for (int i = 0; REQ_TAB[i].method != LAST_METHOD; i++) {
        if (my_strcmp(REQ_TAB[i].action, buffer) == EXIT_SUCCESS) {
            exit_status = REQ_TAB[i].pf(client, REQ_TAB[i].method);
        }
    }
    return EXIT_SUCCESS;
}
