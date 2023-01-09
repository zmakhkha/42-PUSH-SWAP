M_NAME = push_swap
B_NAME = checker
M_SRC = main.c 
B_SRC =  checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS = ft_functions.c ft_functions_2.c parse_input_utils.c parse_input.c push_swap_utils.c sorting_utils.c sorintg_utils_2.c ft_small_sort.c
M_OBJ = $(M_SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all : $(M_NAME)

$(M_NAME) : $(OBJS) $(M_OBJ) 
	@make -C libft
	@make -C ./libft/dll
	@$(CC) $(OBJS) $(M_SRC) libft/libft.a  ./libft/dll/dll.a -o $(M_NAME)
	

%.o	: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C libft
	@make clean -C ./libft/dll
	@rm -f $(M_OBJ) $(B_OBJ) $(OBJS)

fclean : clean
	@make fclean -C libft
	@make fclean -C ./libft/dll
	@rm -f $(M_NAME) $(B_NAME)

re : fclean all

bonus :  $(OBJS) $(B_OBJ)
	@make -C libft
	@make -C ./libft/dll
	@$(CC) $(OBJS) $(B_SRC) $(CFLAGS) libft/libft.a  ./libft/dll/dll.a -o $(B_NAME)

.PHONY: clean fclean all re