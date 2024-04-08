##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makfile Client
##

NAME =	client

CPPFLAGS += -iquote "../include"	\

CFLAGS = -Wall -Wextra -fshort-enums

SRC	=	src/main.c 	\
		src/my_client.c	\
		src/send_request.c 	\
		src/action/sign_action.c 	\
		src/action/login_action.c 	\
		src/recv_request.c 	\
		src/action/send_action.c 	\

LDFLAGS += -lmy

LDLIBS += -L../

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
