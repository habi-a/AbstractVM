CC		= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror -Wpedantic
CFLAGS 	+= 	-lm
CFLAGS	+= 	-I ./inc

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
