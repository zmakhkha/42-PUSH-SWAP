NAME = push_swap
SRC = 	parse_input.c	main.c	push_swap_utils.c	s_list_d_utils.c	main.c
		

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all: $(NAME) libft

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) libft/libft.a -o $(NAME) 

%.o : %.c push_swap.h 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean:
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)

re	: fclean all

.PHONY: clean fclean all re libft