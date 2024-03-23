##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_client
##

NAME =	server

CPPFLAGS += -iquote "../include"	\

CFLAGS = -Wall -Wextra

SRC	=	src/main.c 	\
		src/my_server.c \
		src/connect_clients.c 	\

CC	=	clang

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += -g3
debug: all

re: fclean all

.PHONY: all clean fclean re debug
