/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:53:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/08 18:45:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list_d **a, char *c, int i)
{
	t_list_d	*tmp;
	t_list_d	*pos;

	pos = *a;
	if (pos && pos->prev)
	{
		tmp = pos->prev;
		pos->prev = pos->prev->prev;
		if (pos->prev)
			pos->prev->next = pos;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_front_d(&pos, tmp);
		*a = pos;
		if (i)
		{
			write(1, "s", 1);
			write(1, c, ft_strlen(c));
			write(1, "\n", 1);
		}
	}
}

void	push(t_list_d **src, t_list_d **dst, char *c, int i)
{
	t_list_d	*tmp;

	if (src && *src)
	{
		tmp = *src;
		*src = (*src)->prev;
		tmp->prev = NULL;
		ft_lstadd_front_d(dst, tmp);
		if (i)
		{
			write(1, "p", 1);
			write(1, c, ft_strlen(c));
			write(1, "\n", 1);
		}
	}
}

void	rotate(t_list_d **a, char *c, int i)
{
	t_list_d	*tmp;

	if (a && *a && (*a)->prev)
	{
		tmp = *a;
		(*a) = (*a)->prev;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_back_d(a, tmp);
		if (i)
		{
			write(1, "r", 1);
			write(1, c, ft_strlen(c));
			write(1, "\n", 1);
		}
	}
}

void	reverse_rotate(t_list_d **a, char *c, int i)
{
	t_list_d	*tmp;
	t_list_d	*last;

	if (a && *a && (*a)->prev)
	{
		tmp = *a;
		last = ft_get_end_d(tmp);
		last->next->prev = NULL;
		last->next = NULL;
		ft_lstadd_front_d(&tmp, last);
		*a = tmp;
		if (i)
		{
			write(1, "rr", 2);
			write(1, c, ft_strlen(c));
			write(1, "\n", 1);
		}
	}
}
