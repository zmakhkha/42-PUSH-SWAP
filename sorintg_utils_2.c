/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorintg_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:06:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/09 12:23:42 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_tob_utils(t_list_d **a, t_list_d **b, int i)
{
	if (i == 1)
	{
		push(a, b, "b", 1);
		if (ft_lst_len(*b) > 1 && (*b)->prev->index > (*b)->index)
			swap(b, "b", 1);
	}
	else if (i == 2)
	{
		push(a, b, "b", 1);
		rotate(b, "b", 1);
	}
}

// accept an indexed list
void	push_to_b(t_list_d **a, t_list_d **b)
{
	int	i;
	int	j;

	ft_index_it(a);
	j = ft_get_range(*a);
	i = 0;
	while (ft_lst_len(*a))
	{
		ft_position_it(a);
		if ((*a)->index < i)
		{
			ft_push_tob_utils(a, b, 1);
			i++;
		}
		else if ((*a)->index <= j + i)
		{
			ft_push_tob_utils(a, b, 2);
			i++;
		}
		else
			rotate(a, "a", 1);
		if (ft_lst_len(*b) == 2 && (*b)->index < (*b)->prev->index)
			swap(b, "b", 1);
	}
}

// push the max from b to a
void	ft_push_it_back(t_list_d **a, t_list_d **b)
{
	int	middle;
	int	max_pos;

	while (ft_lst_len(*b))
	{
		ft_position_it(b);
		middle = ft_lst_len(*b) / 2;
		max_pos = ft_get_max(*b)->position;
		if (max_pos > middle)
		{
			max_pos = ft_lst_len(*b) - max_pos + 2;
			while (--max_pos)
				reverse_rotate(b, "b", 1);
			push(b, a, "a", 1);
		}
		else
		{
			max_pos = ft_get_max(*b)->position;
			while (--max_pos)
				rotate(b, "b", 1);
			push(b, a, "a", 1);
		}
	}
}
