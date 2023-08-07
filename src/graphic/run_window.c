/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** run_window
*/

#include "struct.h"
#include "macro.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "graphics.h"

window_set *init_window(void)
{
    window_set *my_win = malloc(sizeof(window_set));

    if (my_win == NULL) {
        return NULL;
    }
    my_win->mode.width = 500;
    my_win->mode.height = 357;
    my_win->mode.bitsPerPixel = 32;
    my_win->my_win = sfRenderWindow_create(my_win->mode, "Gaming Window", sfDefaultStyle, NULL);
    my_win->bg_spt = sfSprite_create();
    my_win->bg_text = sfTexture_createFromFile("assets/background.png", NULL);
    sfSprite_setTexture(my_win->bg_spt, my_win->bg_text, sfFalse);
    return my_win;
}

int window_loop(void)
{
    window_set *my_win = init_window();

    if (my_win == NULL) {
        return EXIT_FAIL;
    }
    while (sfRenderWindow_isOpen(my_win->my_win)) {
        main_event(my_win);
        sfRenderWindow_drawSprite(my_win->my_win, my_win->bg_spt, NULL);
        sfRenderWindow_display(my_win->my_win);
    }
    return EXIT_SUCCESS;
}