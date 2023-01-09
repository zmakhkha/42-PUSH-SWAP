/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:55:27 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/07 18:58:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
