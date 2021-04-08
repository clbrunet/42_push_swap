NAME = checker

SRCS = srcs/ft/ctype.c					\
	   srcs/ft/stdlib.c					\
	   srcs/ft/string.c					\
	   srcs/dput.c						\
	   srcs/parsing/error.c				\
	   srcs/parsing/args.c				\
	   srcs/parsing/input2.c			\
	   srcs/parsing/input.c				\
	   srcs/execution/swap.c			\
	   srcs/execution/push.c			\
	   srcs/execution/rotate.c			\
	   srcs/execution/reverse_rotate.c	\
	   srcs/execution/operations.c		\
	   srcs/main.c

OBJS = $(SRCS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -I./includes/ -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
