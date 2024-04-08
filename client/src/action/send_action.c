/*
** EPITECH PROJECT, 2024
** Kinder_Bueno
** File description:
** handle_send
*/

#include <stdio.h>
#include "macro.h"
#include "client.h"
#include "my_string.h"

int handle_send(struct client_in *client, method_t method)
{
    char buffer[BUFFER_MAX] = {0};
    char *message = NULL;
    char *user = NULL;
    size_t n = 0;

    if (client->username[0] == '\0') {
        printf("You're not connected yet\n");
        return EXIT_SUCCESS;
    }
    buffer[0] = (char)SEND;
    printf("Enter the name of the user : \n");
    if (getline(&user, &n, stdin) < 0) {
        return EXIT_FAIL;
    }
    printf("Enter a message : \n");
    if (getline(&message, &n, stdin) < 0) {
        return EXIT_FAIL;
    }
    clean_line(user);
    clean_line(message);
    my_strncat(buffer, user, 128);
    my_strcpy(&buffer[1 + 128], message);
    printf("You send > %s\n", &buffer[129]);
    if (send(client->socket, buffer, BUFFER_MAX, 0) < 0) {
        perror("send");
    }
    return EXIT_SUCCESS;
}
