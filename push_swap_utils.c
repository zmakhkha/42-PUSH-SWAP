/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:53:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/02 18:49:50 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <libc.h>

void	swap(t_list_d **a, char *c)
{
	t_list_d	*tmp;
	t_list_d	*pos;

	pos = *a;
	if (pos && pos->prev)
	{		
		tmp = pos -> prev;
		pos -> prev = pos -> prev -> prev;
		if (pos -> prev)
			pos -> prev -> next = pos;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_front_d(&pos, tmp);
		write(1, "s", 1);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
		*a = pos ;
	}
}

void	push( t_list_d **src, t_list_d **dst, char *c)
{
	t_list_d	*tmp;

	if (src && *src)
	{
		tmp = *src;
		*src = (*src)-> prev;
		tmp -> prev = NULL;
		ft_lstadd_front_d(dst, tmp);
		write(1, "p", 1);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
	}
}

void	rotate(t_list_d **a, char *c)
{
	t_list_d	*tmp;
	t_list_d	*head;
	t_list_d	*last;

	if (a && *a && (*a)->prev)
	{
		head = (*a);
		last = ft_get_end_d(head);
		if (head -> prev == last)
		{
			swap(a, "a");
			return ;
		}
		tmp = *a;
		(*a) = (*a)-> prev;
		tmp -> prev -> next = NULL;
		tmp -> prev = NULL;
		ft_lstadd_back_d(a, tmp);
		write(1, "r", 1);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_list_d **a, char *c)
{
	t_list_d	*tmp;
	t_list_d	*last;

	if (a && *a && (*a)-> prev)
	{			
		tmp = *a;
		last = ft_get_end_d(tmp);
		if (tmp -> prev == last)
			swap(a, c);
		else
		{
			last -> next -> prev = NULL;
			last -> next = NULL;
			ft_lstadd_front_d(&tmp, last);
			*a = tmp;
			write(1, "rr", 2);
			write(1, c, ft_strlen(c));
			write(1, "\n", 1);
		}
	}
}
