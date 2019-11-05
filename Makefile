##
## ETNA PROJECT, 31/10/2019 by courta_f
## c:\Users\Fr4nck\Desktop\group-716039
## File description:
##      Makefile Générique
##

CC		= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror -Wpedantic
CFLAGS 	+= 	-lm
CFLAGS	+= 	-I ./inc
CFLAGS 	+= 	-I $(LIBPATH)inc
LDFLAGS	=	$(LIBMY)

LIBMY	= 	-L ./ -lmy
LIBNAME	= 	libmy
LIBPATH	= 	./libmy/

NAME	=	abstractvm

SRC		= 	src/main.c \
			src/instructions/add.c \
			src/instructions/assert.c \
			src/instructions/div.c \
			src/instructions/dump.c \
			src/instructions/instruction.c \
			src/instructions/mod.c \
			src/instructions/mul.c \
			src/instructions/pop.c \
			src/instructions/print.c \
			src/instructions/push.c \
			src/instructions/sub.c \
			src/interpreter/ast_node.c \
			src/interpreter/ast_node_extra.c \
			src/interpreter/interpreter.c \
			src/interpreter/interpret_node.c \
			src/lexer_parser/get_tokens.c \
			src/lexer_parser/parser.c\
			src/lexer_parser/parser_factor.c\
			src/lexer_parser/parser_utils.c\
			src/lexer_parser/token.c \
			src/stack/stack.c \
			src/types/types.c \
			src/types/type.c

OBJ		= 	$(SRC:.c=.o)

RM		= 	rm -f
LN		= 	ln -sf

all:		$(LIBNAME) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)


$(LIBNAME):	$(OBJ)
	make -C $(LIBPATH)
	$(LN)  $(LIBPATH)$(LIBNAME).so ./$(LIBNAME).so
	$(LN)  $(LIBPATH)$(LIBNAME).a ./$(LIBNAME).a

clean:
	$(RM) $(OBJ)
	make -C $(LIBPATH) clean

fclean: 	clean
	$(RM) $(NAME)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a
	make -C $(LIBPATH) fclean

re:			fclean all

.PHONY	= 	all $(NAME) $(LIBNAME) clean fclean re
