/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorintg_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:06:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/06 18:24:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_get_range(t_list_d *a)
{
	int	size;
	int	range;

	range = 0;
	if (a)
	{
		size = ft_lst_len(a);
		if(size > 500)
			range = 30;
		else if (size > 100)
			range = 15;
		else range = size / 2;
	}
	return (range);
}

//void	max_to_top(t_list_d **lst)
//{
//	t_list_d	*last;
//	int			index;

//	if (lst && *lst && (*lst) -> prev)
//	{
//		ft_index_it(lst);
//		index = 1;
//		last = ft_get_end_d(lst);
//		while (index)
//		{
//			if ((*lst) -> index < (*lst) -> prev ->index)
//			{
//				swap(lst, "b");
//				index = 1;
//			}
//			else if ((*lst) -> index < last -> prev ->index)
//			{
//				rotate(lst, "b");
//				index = 1;
//			}
//			else
//				index = 0;
//		}
		
//	}	
//}


// tan3adwha bl len dial stack
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
			list = list ->prev;
		}
		return (tmp);
	}
	return (NULL);
}

// accept an indexed list
void	push_to_b(t_list_d **a, t_list_d **b)
{
	int			i;
	int			j;
	int			min_pos;


	ft_index_it(a);
	j = ft_get_range(*a);
	i = 0;
	while (a && ft_lst_len(*a))
	{
		ft_position_it(a);
		min_pos = ft_get_min(*a)->position;
		if ((*a) -> index < i)
		{
			//printf("hnaaa\n");
			push(a, b, "b");
			i++;
			//rotate(a, "a");
		}
		else if ((*a) -> index <= j + i)
		{
			push(a, b, "b");
			rotate(b, "b");
			i++;
		}
		else
		{
			rotate(a, "a");
		}
		
	}
}

// push the max from b to a
void ft_push_it_back(t_list_d **a, t_list_d **b)
{
		int	middle;
		int	max_pos;
		int	tmp_pos;


		while (ft_lst_len(*b))
		{
			ft_position_it(b);
			middle = ft_lst_len(*b) / 2;
			max_pos = ft_get_max(*b) -> position;
			if (max_pos > middle)
			{
				tmp_pos = ft_lst_len(*b) - max_pos + 2;
				while (--tmp_pos)
					reverse_rotate(b, "b");
				push(b, a, "a");
			}
			else
			{
				max_pos = ft_get_max(*b) -> position;
				while (--max_pos)
					rotate (b, "b");
				push(b, a, "a");
			}
		}
}
