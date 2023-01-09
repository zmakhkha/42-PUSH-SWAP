NAME = dll.a
SRC = ft_del_one.c ft_get_end_d.c ft_lstadd_back_d.c ft_lstadd_front_d.c ft_lstnew_d.c ft_free_list_d.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wextra -Wall -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc	$(NAME) $(OBJ)

%.o	: %.c dll.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(OBJ) $(NAME)

norm :
	@norminette $(SRC)

re : fclean all

.PHONY: clean fclean all re libft