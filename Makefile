NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap

SRCS_SHARED = srcs/shared/ft/ctype.c					\
			  srcs/shared/ft/stdlib.c					\
			  srcs/shared/ft/string.c					\
			  srcs/shared/dput.c						\
			  srcs/shared/parsing/args.c				\
			  srcs/shared/execution/swap.c				\
			  srcs/shared/execution/push.c				\
			  srcs/shared/execution/rotate.c			\
			  srcs/shared/execution/reverse_rotate.c	\
			  srcs/shared/execution/operations.c		\
			  srcs/shared/execution/check_stacks.c
OBJS_SHARED = $(SRCS_SHARED:.c=.o)
$(OBJS_SHARED): EXTRA_CFLAGS_I :=

SRCS_CHECKER = srcs/checker/parsing/input2.c		\
			   srcs/checker/parsing/input.c			\
			   srcs/checker/execution/operations.c	\
			   srcs/checker/main.c
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
$(OBJS_CHECKER): EXTRA_CFLAGS_I := -I./includes/checker/

SRCS_PUSH_SWAP = srcs/push_swap/execution/stack_rotate_sort_utils.c	\
				 srcs/push_swap/execution/stack_rotate_sort_utils2.c\
				 srcs/push_swap/execution/stack_rotate_sort.c		\
				 srcs/push_swap/execution/merge_sort.c				\
				 srcs/push_swap/execution/perfect_sort_utils.c		\
				 srcs/push_swap/execution/perfect_sort.c			\
				 srcs/push_swap/execution/sort_stacks.c				\
				 srcs/push_swap/main.c
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
$(OBJS_PUSH_SWAP): EXTRA_CFLAGS_I := -I./includes/push_swap/

CC = clang
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -I./includes/

.c.o:
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS_I) -o $@ -c $<

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER): $(OBJS_SHARED) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) -I./includes/checker/ -o $(NAME_CHECKER) $(OBJS_SHARED) $(OBJS_CHECKER)


$(NAME_PUSH_SWAP): $(OBJS_SHARED) $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) -I./includes/push_swap/ -o $(NAME_PUSH_SWAP) $(OBJS_SHARED) $(OBJS_PUSH_SWAP)

bonus: all

clean:
	rm -f $(OBJS_SHARED) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean: clean
	rm -f $(OBJS_SHARED) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all

.PHONY: all bonus clean fclean re
