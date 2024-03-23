##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_server
##

all:
	make -C server
	make -C client

clean:
	make -C server clean
	make -C client clean

fclean:
	make -C server fclean
	make -C client fclean

debug: 	make -C server debug
debug: 	make -C client debug

re: fclean all

.PHONY: all clean fclean re debug
