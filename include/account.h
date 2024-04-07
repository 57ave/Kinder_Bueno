/*
** EPITECH PROJECT, 2023
** Kinder_bueno
** File description:
** account
*/

    #include "hashtable.h"
    #include "my_unistd.h"
    #include "my_socket.h"
    #include "client.h"

    #define LEN_TAB_ACCOUNT 100

enum code_account {
    OK = 1,
    ALREADY_EXIST,
    ALREADY_CONNECTED,
    NOT_FOUND,
    WRONG_PASSWORD,
    FAIL,
};

enum code_account new_account(hashtable_t *ht, struct data_128 *data);

enum code_account connect_account(hashtable_t *ht, struct data_128 *data);

hashtable_t *init_account_tab(void);

int register_account(hashtable_t *ht, int client_socket, struct data_128 *user_data);

int already_connected_account(int client_socket);

int check_connected_account(struct server_in *serv, struct data_128 *data);

int login_account(hashtable_t *ht, int client_socket, struct data_128 *user_data);
