/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:18:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/09 12:25:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// index the list
void	ft_index_it(t_list_d **list)
{
	int			i;
	t_list_d	*pos;
	t_list_d	*lst;

	if (list && *list)
	{
		i = 0;
		pos = *list;
		lst = *list;
		while (lst)
		{
			i = 0;
			pos = *list;
			while (pos)
			{
				if (lst->content > pos->content)
					i++;
				pos = pos->prev;
			}
			lst->index = i;
			lst = lst->prev;
		}
	}
}

void	ft_position_it(t_list_d **lst)
{
	int			i;
	t_list_d	*pos;

	i = 1;
	if (lst && *lst)
	{
		pos = *lst;
		while (pos)
		{
			pos->position = i;
			i++;
			pos = pos->prev;
		}
	}
}

int	ft_lst_len(t_list_d *a)
{
	int				i;
	t_list_d		*t;

	i = 0;
	if (a)
	{
		t = a;
		while (t)
		{
			i++;
			t = t->prev;
		}
	}
	return (i);
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

// Get the last node in the list
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
