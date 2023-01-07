/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorintg_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:06:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/07 17:46:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get the range
int	ft_get_range(t_list_d *a)
{
	int	size;
	int	range;

	range = 0;
	if (a)
	{
		size = ft_lst_len(a);
		if (size > 250)
			range = 42;
		else
			range = 15;
	}
	return (range);
}

// Possible with th len of the stack
t_list_d	*ft_get_max(t_list_d *a)
{
	t_list_d	*max;

	while (a)
	{
		max = a;
		while (a)
		{
			if (a->content > max->content)
				max = a;
			a = a->prev;
		}
		return (max);
	}
	return (NULL);
}

t_list_d	*ft_get_end_de(t_list_d *list)
{
	t_list_d	*tmp;

	if (list)
	{
		tmp = list;
		while (list)
		{
			tmp = list;
			list = list->prev;
		}
		return (tmp);
	}
	return (NULL);
}

// accept an indexed list
void	push_to_b(t_list_d **a, t_list_d **b)
{
	int	i;
	int	j;
	int	min_pos;

	ft_index_it(a);
	j = ft_get_range(*a);
	i = 0;
	while (a && ft_lst_len(*a))
	{
		ft_position_it(a);
		min_pos = ft_get_min(*a)->position;
		if ((*a)->index < i)
		{
			push(a, b, "b");
			if (ft_lst_len(*b) > 1 && (*b)->prev->index > (*b)->index)
				swap(b, "b");
			i++;
		}
		else if ((*a)->index <= j + i)
		{
			push(a, b, "b");
			rotate(b, "b");
			i++;
		}
		else
		{
			rotate(a, "a");
		}
		if (ft_lst_len(*b) == 2 && (*b)->index < (*b)->prev->index)
			swap(b, "b");
	}
}

// push the max from b to a
void	ft_push_it_back(t_list_d **a, t_list_d **b)
{
	int	middle;
	int	max_pos;
	int	tmp_pos;

	while (ft_lst_len(*b))
	{
		ft_position_it(b);
		middle = ft_lst_len(*b) / 2;
		max_pos = ft_get_max(*b)->position;
		if (max_pos > middle)
		{
			tmp_pos = ft_lst_len(*b) - max_pos + 2;
			while (--tmp_pos)
			{
				reverse_rotate(b, "b");
			}
			push(b, a, "a");
		}
		else
		{
			max_pos = ft_get_max(*b)->position;
			while (--max_pos)
			{
				rotate(b, "b");
			}
			push(b, a, "a");
		}
	}
}
