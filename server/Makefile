##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_client
##

NAME =	server

CPPFLAGS += -iquote "../include"	\

CFLAGS = -Wall -Wextra -fshort-enums

LDFLAGS += -lmy

LDLIBS += -L../

SRC	=	src/main.c 	\
		src/my_server.c \
		src/connect_clients.c 	\
		src/handle_client.c 	\
		src/account_handling/register_account.c 	\
		src/account_handling/login_account.c 	\
		src/account_handling/manage_account_tab.c 	\
		src/account_handling/already_exist_account.c \
		src/send_method.c

CC	=	clang

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += -g3
debug: all

re: fclean all

.PHONY: all clean fclean re debug
