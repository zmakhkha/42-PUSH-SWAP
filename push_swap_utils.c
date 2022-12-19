/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:53:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/19 18:05:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <libc.h>

void	swap(t_list_d *a)
{
	t_list_d	*tmp;

	if (a && a->next)
	{		
		tmp = a->next;
		a = a->next;
		ft_lstadd_front_d(&a, tmp);
		free(tmp);
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

void	rotate(t_list_d **a)
{
	t_list_d	*tmp;

	if (a)
	{
		tmp = *a;
		tmp ->next = NULL;
		ft_lstadd_back_d(a, tmp);
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
