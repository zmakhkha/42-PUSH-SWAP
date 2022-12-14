/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:53:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/13 19:59:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <libc.h>

void	swap(t_list *a)
{
	t_list	*tmp;

	if (a && a->next)
	{		
		tmp = a->next;
		a = a->next;
		ft_lstadd_front(&a, tmp);
	}
}

void	push( t_list **a, t_list *b)
{
	t_list	*tmp;

	if (b)
	{
		tmp = b;
		b = b -> next;
		if (a)
			ft_lstadd_front(a, tmp);
		else
			ft_lstnew(tmp -> content);
		free(tmp);
	}
}

void	rotate(t_list **a)
{
	t_list	*tmp;

	if (a)
	{
		tmp = *a;
		tmp ->next = NULL;
		ft_lstadd_back(a, tmp);
	}
}

void	reverse_rotate(t_list **a)
{
	t_list	*tmp;

	if (a)
	{
		while ((*a)-> next)
			*a = (*a)-> next;
	tmp = *a;
		ft_lstadd_front(a, tmp);
	}
}
