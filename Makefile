##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	main.c 					\
		linked_list/add_node.c	\
		src/parser.c			\
		src/free.c				\
		src/room.c				\
		src/my_tablength.c		\

LIB = 	$(wildcard lib/my/*.c)

MY_PRINTF = 	$(wildcard lib/my_printf/*.c)

NAME	=	lem_in

OBJ	=	libmy.a

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:
	gcc -o $(NAME) $(SRC) $(LIB) $(MY_PRINTF) $(ERROR) $(VG)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
