/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:55:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/20 16:40:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP
#define PUSH_SWAP
#include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				position;
	int 			index;
	int				content;
} t_list_d;

int	ft_check_input(int n, char **table);
int	ft_isnumber(char *number);

void		ft_lstadd_front_d(t_list_d **lst, t_list_d *new);
void		ft_lstadd_back_d(t_list_d **lst, t_list_d *back);
t_list_d	*ft_fill_it(char **args);
t_list_d	*ft_lstnew_d(int content);
t_list_d 	*ft_get_end_d(t_list_d *list);

void	swap(t_list_d *a);
void	push( t_list_d **a, t_list_d *b);
void	rotate(t_list_d **a);
void	reverse_rotate(t_list_d **a);

#endif