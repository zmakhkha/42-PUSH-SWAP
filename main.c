/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/10 18:53:41 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_one(t_list_d **a, t_list_d **b)
{
	if (ft_lst_len(*a) == 2 && (*a)->prev->index < (*a)->index)
		swap(a, "a", 1);
	else if (ft_lst_len(*a) == 3)
		ft_sort_tree(a, "a");
	else if (ft_lst_len(*a) == 4)
		ft_sort_four(a, b);
	else if (ft_lst_len(*a) == 5)
		ft_sort_five(a, b);
	else
	{
	}
}

int	main(int n, char **v)
{
	t_list_d	*a;
	t_list_d	*b;

	a = ft_parse_it(n, v);
	ft_index_it(&a);
	if (!ft_issorted(a))
	{
		if (ft_lst_len(a) <= 5)
			ft_part_one(&a, &b);
		else
		{
			push_to_b(&a, &b);
			ft_push_it_back(&a, &b);
		}
	}
	ft_free_list_d(&a);
	return (0);
}
