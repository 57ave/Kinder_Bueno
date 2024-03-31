##
## EPITECH PROJECT, 2023
## makefile
## File description:
## stdlib
##

NAME =	libtree.a

CC = gcc

CPPFLAGS += -iquote "../include"

CFLAGS = -Wall -Wextra

RM = rm -f

LD_PATH = ../../libtree.a

SRC =	src/btree_apply_by_level.c	\
		src/btree_apply_infix.c	\
		src/btree_apply_prefix.c	\
		src/btree_apply_suffix.c	\
		src/btree_create.c	\
		src/btree_create_node.c	\
		src/btree_insert_data.c	\
		src/btree_level_count.c	\
		src/btree_search_item.c	\

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) $(LD_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LD_PATH)


debug: CFLAGS += -ggdb3
debug: all

re: fclean
re: all

.PHONY: all clean fclean re debug
