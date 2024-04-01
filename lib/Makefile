##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compil and create the lib
##

LIST_LIB	= 	liblist/my_apply_on_nodes.c	\
				liblist/my_delete_nodes.c	\
				liblist/my_find_node.c		\
				liblist/my_add_node.c		\
				liblist/my_put_node.c 		\
				liblist/my_find_node.c 		\
				liblist/list_to_tab.c 		\
				liblist/my_list_size.c

STD_LIB 	= 	stdlib/free_array.c 	\

STR_LIB 	= 	string/my_strdup_delim.c \
				string/my_strlen.c 	\
				string/my_perror.c 	\
				string/my_strcmp.c 	\
				string/my_stwa.c 	\
				string/my_strcat.c 	\
				string/clean_line.c

BTREE_LIB 	= 	bin_tree/btree_apply_infix.c	\
				bin_tree/btree_apply_prefix.c	\
				bin_tree/btree_apply_suffix.c	\
				bin_tree/btree_create.c	\
				bin_tree/btree_create_node.c	\
				bin_tree/btree_insert_data.c	\
				bin_tree/btree_level_count.c	\
				bin_tree/btree_search_item.c	\

CFLAGS 	=	 -Wall -Wextra

CPPFLAGS += -iquote "include"

SRC = 	$(LIST_LIB) \
		$(STD_LIB) 	\
		$(STR_LIB) 	\
		$(BTREE_LIB)

OBJ    =    $(SRC:.c=.o)

NAME_LIB   =    libmy.a

NAME_HEADER    =	include/my_list.h 	\
					include/my_stdlib.h \
					include/my_string.h \
					include/btree.h

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	cp $(NAME_HEADER) ../include/
	cp $(NAME_LIB) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME_LIB)
	$(RM) ../$(NAME_LIB)
