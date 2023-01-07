/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/07 17:51:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "push_swap.h"

void	checkceaks(void)
{
	system("leaks push_swap");
}

int	main(int n, char **v)
{
	t_list_d	*a;
	t_list_d	*tmp;
	t_list_d	*b;
	int			len;

	ft_parse_it(n, v);
	a = ft_fill_it(v);
	tmp = a;
	ft_position_it(&tmp);
	ft_index_it(&tmp);
	ft_sort_five(&a, &b);
	len = ft_lst_len(a);
	if (len == 3)
		ft_sort_tree(&a, "a");
	else if (len == 4)
		ft_sort_four(&a, &b);
	else if (len == 5)
		ft_sort_five(&a, &b);
	else
	{
		push_to_b(&a, &b);
		ft_push_it_back(&a, &b);
	}
	return (0);
}
