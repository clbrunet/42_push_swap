CHECKER = checker_folder/checker
PUSH_SWAP = push_swap_folder/push_swap

all: checker push_swap

$(CHECKER):
	make -C checker_folder/

$(PUSH_SWAP):
	make -C push_swap_folder/

checker: $(CHECKER)
	cp checker_folder/checker .

push_swap: $(PUSH_SWAP)
	cp push_swap_folder/push_swap .

bonus: all

clean_checker:
	make -C checker_folder/ clean

clean_push_swap:
	make -C push_swap_folder/ clean

clean: clean_checker clean_push_swap

fclean_checker:
	make -C checker_folder/ fclean
	rm -f checker

fclean_push_swap:
	make -C push_swap_folder/ fclean
	rm -f push_swap

fclean: fclean_checker fclean_push_swap

re_checker: fclean_checker checker

re_push_swap: fclean_push_swap push_swap

re: re_checker re_push_swap

.PHONY: all bonus clean_checker clean_push_swap clean fclean_checker fclean_push_swap fclean re_checker re_push_swap re
