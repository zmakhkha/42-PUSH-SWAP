/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:57:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/08 18:50:35 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_utils(t_list_d **a, char *c, int i)
{
	if (i == 2)
	{
		swap(a, c, 1);
		reverse_rotate(a, c, 1);
	}
	else if (i == 4)
	{
		swap(a, c, 1);
		rotate(a, c, 1);
	}
	else if (i == 5)
	{
		rotate(a, c, 1);
		rotate(a, c, 1);
	}
}

// Sort three
void	ft_sort_tree(t_list_d **a, char *c)
{
	if (a && *a && (*a)-> prev && (*a)-> prev -> prev && !ft_issorted(*a))
	{
		ft_index_it(a);
		if ((*a)->prev->prev->index > (*a)->index \
		&& (*a)->index > (*a)->prev->index)
			swap(a, c, 1);
		else if ((*a)->index > (*a)->prev->index && (*a)-> \
		prev->index > (*a)-> prev ->prev ->index)
			ft_sort_three_utils(a, c, 2);
		else if ((*a)->index > (*a)-> prev ->prev ->index \
		&& (*a)-> prev ->prev ->index > (*a)->prev->index)
			rotate(a, c, 1);
		else if ((*a)-> prev -> index > (*a)-> prev ->prev ->index \
		&& (*a)-> prev ->prev ->index > (*a)->index)
			ft_sort_three_utils(a, c, 4);
		else if ((*a)-> prev -> index > (*a)-> index && \
		(*a)-> index > (*a)-> prev ->prev ->index)
			reverse_rotate(a, c, 1);
		else if ((*a)-> index < (*a)->prev->index && (*a)->prev->index)
			ft_sort_three_utils(a, c, 5);
	}
}

// accept an indexed and positionned list
void	ft_sort_four(t_list_d **a, t_list_d **b)
{
	int	tmp_pos;

	ft_position_it(a);
	if (a && *a && ft_lst_len(*a) == 4 && !ft_issorted(*a))
	{
		if (ft_get_min(*a)->position > 2 && !ft_issorted(*a))
		{
			tmp_pos = ft_lst_len(*a) - ft_get_min(*a)->position + 2;
			while (-- tmp_pos)
				reverse_rotate(a, "a", 1);
			push(a, b, "b", 1);
			ft_sort_tree(a, "a");
			push(b, a, "a", 1);
		}
		else
		{
			tmp_pos = ft_get_min(*a)->position;
			while (--tmp_pos)
				rotate(a, "a", 1);
			push(a, b, "b", 1);
			ft_sort_tree(a, "a");
			push(b, a, "a", 1);
		}
	}
}

// Sort five elements
void	ft_sort_five(t_list_d **a, t_list_d **b)
{
	int	tmp_pos;

	if (a && *a && ft_lst_len(*a) == 5 && !ft_issorted(*a))
	{
		ft_position_it(a);
		if (ft_get_min(*a)->position > 2)
		{
			tmp_pos = ft_lst_len(*a) - ft_get_min(*a)->position + 2;
			while (-- tmp_pos)
				reverse_rotate(a, "a", 1);
			push(a, b, "b", 1);
			ft_sort_four(a, b);
			push(b, a, "a", 1);
		}
		else
		{
			tmp_pos = ft_get_min(*a)->position;
			while (--tmp_pos)
				rotate(a, "a", 1);
			push(a, b, "b", 1);
			ft_sort_four(a, b);
			push(b, a, "a", 1);
		}
	}
}
