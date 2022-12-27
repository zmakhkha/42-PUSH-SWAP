/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:53:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/27 17:43:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <libc.h>


void	ft_lstadd_front_dddd(t_list_d **lst, t_list_d *new)
{
	if (lst && new)
	{
		if (*lst && new)
		{
			new ->prev = *lst;
			(*lst)-> next = new;
		}
	(*lst) = new;
	}
}

void	swap(t_list_d **a, char *c)
{
	t_list_d	*tmp;
	t_list_d	*pos;

	pos = *a;
	if (pos && pos->prev)
	{		
		tmp = pos -> prev;
		pos -> prev = pos -> prev -> prev;
		pos -> prev -> next = pos;
		
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_front_dddd(&pos, tmp);		
		write(1, "swap ", 5);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
		*a = pos ;
	}
}

void	push( t_list_d **a, t_list_d *b)
{
	t_list_d	*tmp;

	if (b)
	{
		tmp = b;
		b = b -> next;
		if (a)
			ft_lstadd_front_d(a, tmp);
		else
			ft_lstnew_d(tmp -> content);
		free(tmp);
	}
}

void	rotate(t_list_d **a, t_list_d *head, t_list_d *last, char *c)
{
	t_list_d	*tmp;

	if (a && head && last)
	{
		tmp = *a;
		tmp -> prev -> next = NULL;
		free(tmp);
		tmp = last;
		tmp -> next -> prev = NULL;
		free (tmp);
		ft_lstadd_back_d(a, head);
		ft_lstadd_front_d(a, head);
		write(1, "rotate ", 8);
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_list_d **a)
{
	t_list_d	*tmp;

	if (a)
	{
		while ((*a)-> next)
			*a = (*a)-> next;
	tmp = *a;
		ft_lstadd_front_d(a, tmp);
	}
}
