##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/my_put.c	\
		src/main.c	\
		src/connexion.c	\
		src/playerone.c	\
		src/playertwo.c	\
		src/game_loop.c	\
		src/my_strlen.c	\
		src/waiting.c	\
		src/my_get_nbr.c	\
		src/place_boat.c	\
		src/placeboat2.c	\
		src/placeboat3.c	\
		src/placeboat4.c	\
		src/placeboat5.c	\
		src/fct.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I include/ -g -W -Wall -Wextra

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean my
