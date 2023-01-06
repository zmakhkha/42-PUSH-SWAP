NAME = push_swap
SRC = main.c ft_functions.c parse_input_utils.c parse_input.c push_swap_utils.c sorting_utils.c sorintg_utils_2.c
		

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C ./libft/dll
	@$(CC) $(SRC) libft/libft.a  ./libft/dll/dll.a -o $(NAME) -g #-fsanitize=address
	
	

%.o	: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C libft
	@rm -f $(OBJ)

fclean :
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)

norm :
	norminette $(SRC)

re : fclean all

.PHONY: clean fclean all re norm