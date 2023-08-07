##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_server
##

NAME =	server

CPPFLAGS += -iquote "include"	\

CFLAGS = -Wall -Wextra

CSFMLINK = 	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\

SRC	=	src/main.c 	\
		src/networking/my_server.c	\
		src/networking/create_adress.c	\
		src/graphic/run_window.c \
		src/graphic/main_event.c \


OBJ = 	$(SRC:.c=.o)

OBJ_TEST = $(TEST)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CSFMLINK)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += -g3
debug: all

re: fclean all

.PHONY: all clean fclean re debug
