/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:55:27 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/07 17:53:20 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tree(t_list_d **a, char *c)
{
	if (a && *a && (*a)-> prev && (*a)-> prev -> prev && !ft_issorted(*a))
	{
		if ((*a)->prev->prev->index > (*a)->index \
		&& (*a)->index > (*a)->prev->index)
			swap(a, c);
		else if ((*a)->index > (*a)->prev->index && (*a)-> \
		prev->index > (*a)-> prev ->prev ->index)
		{
			swap(a, c);
			reverse_rotate(a, c);
		}
		else if ((*a)->index > (*a)-> prev ->prev ->index \
		&& (*a)-> prev ->prev ->index > (*a)->prev->index)
			rotate(a, c);
		else if ((*a)-> prev -> index > (*a)-> prev ->prev ->index \
		&& (*a)-> prev ->prev ->index > (*a)->index)
		{
			swap(a, c);
			rotate(a, c);
		}
		else if ((*a)-> prev -> index > (*a)-> index && \
		(*a)-> index > (*a)-> prev ->prev ->index)
			reverse_rotate(a, c);
		else if ((*a)-> index < (*a)->prev->index && (*a)->prev->index)
		{
			rotate(a, c);
			rotate(a, c);
		}
	}
}

t_list_d	*ft_get_min(t_list_d *a)
{
	t_list_d	*min;

	if (a)
	{
		min = a;
		while (a)
		{
			if (a->content < min->content)
				min = a;
			a = a->prev;
		}
		return (min);
	}
	return (NULL);
}

int	ft_issorted(t_list_d *lst)
{
	t_list_d	*tmp;

	if (lst && lst -> prev)
	{
		while (lst -> prev)
		{
			tmp = lst;
			lst = lst -> prev;
			if (tmp -> content > lst ->content)
				return (0);
		}
	}
	return (1);
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
				reverse_rotate(a, "a");
			push(a, b, "b");
			ft_sort_tree(a, "a");
			push(b, a, "a");
		}
		else
		{
			tmp_pos = ft_get_min(*a)->position;
			while (--tmp_pos)
				rotate(a, "a");
			push(a, b, "b");
			ft_sort_tree(a, "a");
			push(b, a, "a");
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
				reverse_rotate(a, "a");
			push(a, b, "b");
			ft_sort_four(a, b);
			push(b, a, "a");
		}
		else
		{
			tmp_pos = ft_get_min(*a)->position;
			while (--tmp_pos)
				rotate(a, "a");
			push(a, b, "b");
			ft_sort_four(a, b);
			push(b, a, "a");
		}
	}
}
