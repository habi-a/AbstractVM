CC		= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror -Wpedantic
CFLAGS 	+= 	-lm
CFLAGS	+= 	-I ./inc

NAME	=	abstractvm

SRC		= 	src/main.c \
			src/instructions/instructions.c \
			src/instructions/instruction.c \
			src/interpreter/ast_node.c \
			src/interpreter/interpreter.c \
			src/lexer_parser/parser.c\
			src/lexer_parser/parser_utils.c\
			src/lexer_parser/token.c \
			src/stack/stack.c \
			src/types/types.c \
			src/types/type.c

OBJ		= 	$(SRC:.c=.o)

RM		= 	rm -f
LN		= 	ln -s

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY	= 	all $(NAME) clean fclean re
