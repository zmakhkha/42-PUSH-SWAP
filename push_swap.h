/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:55:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/14 14:16:44 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP
#define PUSH_SWAP
#include "./libft/libft.h"

typedef struct s_node
{
	struct s_list	*prev;
	void			*content;
	struct s_list	*next;
} t_list_d;

int	ft_check_input(char **table);
int	ft_isnumber(char *number);



#endif