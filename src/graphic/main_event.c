/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** main_event
*/
#include "struct.h"
#include "macro.h"

int main_event(window_set *my_win)
{
    while (sfRenderWindow_pollEvent(my_win->my_win, &my_win->event)) {
        if (my_win->event.type == sfEvtClosed)  {
            sfRenderWindow_close(my_win->my_win);
        }
    }
    return EXIT_SUCCESS;
}