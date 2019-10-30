##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CC	= gcc

RM	= rm -f

NAME	= projTester

SRC	=   option/option_one.c \
        main.c  \
        utils/my_strtoword_tab.c    \
        utils/my_tablen.c   \
        option/option_two.c \
        utils/get_line.c    \
        option/option_three.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
