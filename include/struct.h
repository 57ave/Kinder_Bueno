/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Event.h>


typedef struct window_settings {
    sfRenderWindow *my_win;
    sfVideoMode mode;
    sfSprite *bg_spt;
    sfTexture *bg_text;
    sfEvent event;
} window_set;

#endif /* !STRUCT_H_ */
