/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** sign action
*/

#include <stdio.h>
#include "my_socket.h"
#include "macro.h"
#include "stdbool.h"
#include "my_unistd.h"
#include "my_string.h"
#include "client.h"

int get_user_info(struct data *user_info, char *buffer, size_t n)
{
    bool password_wrong = true;

    printf("Enter Username :\n");
    if (getline(&buffer, &n, stdin) < 0) {
        perror("getline");
        return EXIT_FAIL;
    }
    user_info->key = my_strdup_delim(buffer, '\n');
    while (password_wrong) {
        printf("Enter Password :\n");
        if (getline(&buffer, &n, stdin) < 0) {
            perror("getline");
            return EXIT_FAIL;
        }
        if (my_strlen(buffer) < 5) {
            printf("Please use a longer password\n");
        } else {
            password_wrong = false;
        }
    }
    user_info->value = my_strdup_delim(buffer, '\n');
    return EXIT_SUCCESS;
}

int handle_signin(struct client_in *client, method_t method)
{
    char *buffer = NULL;
    size_t n = 0;
    struct data user_info = {0};
    struct request_data request = {0};
    char request_buffer[BUFFER_MAX] = {0};

    if (get_user_info(&user_info, buffer, n) == EXIT_FAIL) {
        return EXIT_FAIL;
    }
    printf("name >%s\npassword%s\n", user_info.key, user_info.value);
    return EXIT_SUCCESS;
}
