##
## Makefile for libmy in /Users/habi_a/Documents
##
## Made by HABI Açal
## Login   <habi_a@etna-alternance.net>
##
## Started on  Thu Jul 12 14:25:31 2018 HABI Açal
## Last update Mon Jul 16 11:29:50 2018 HABI Açal
##
CC	=	gcc
CFLAGS	+=	-Wall -Wextra -Wpedantic -Werror
CFLAGS	+=	-fPIC
CFLAGS	+=	-I ./inc -I ./inc/my_printf

SRC	=	src/my_getnbr.c \
		src/my_isalnum.c \
		src/my_isprintable.c \
		src/my_lowcase.c \
		src/my_nbrlen.c \
		src/my_nbrlen_base.c \
		src/my_printf/my_printf.c \
		src/my_printf/my_put1.c \
		src/my_printf/my_put2.c \
		src/my_printf/my_put3.c \
		src/my_putchar.c \
		src/my_putnbr.c \
		src/my_putnbr_base.c \
		src/my_putstr.c \
		src/my_revert_tab.c \
		src/my_sort_str_tab.c \
		src/my_strcat.c \
		src/my_strcmp.c \
		src/my_strcpy.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_trim.c

OBJ	= 	$(SRC:.c=.o)

NAME	= 	libmy
NAME_STC= 	$(NAME).a
NAME_DYN= 	$(NAME).so

RM	= 	rm -f

all:		$(NAME_STC) $(NAME_DYN)

$(NAME_STC): 	$(OBJ)
	ar rc $(NAME_STC) $(OBJ)
	ranlib $(NAME_STC)

$(NAME_DYN): 	$(OBJ)
	$(CC) -shared $(OBJ) $(CFLAGS) -o $(NAME_DYN)

clean:
	$(RM) $(OBJ) *~ *#

fclean: 	clean
	$(RM) $(NAME_STC) $(NAME_DYN)

re:		fclean all

.PHONY	= 	all $(NAME_STC) $(NAME_DYN) clean fclean re
