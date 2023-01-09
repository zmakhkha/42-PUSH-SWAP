/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:18:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/08 13:43:59 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get the range
int	ft_get_range(t_list_d *a)
{
	int	size;
	int	range;

	range = 0;
	if (a)
	{
		size = ft_lst_len(a);
		if (size > 250)
			range = 42;
		else
			range = 15;
	}
	return (range);
}

void	rr(t_list_d **a, t_list_d **b, int i)
{
	rotate(a, "a", i);
	rotate(b, "b", i);
}

void	rrr(t_list_d **a, t_list_d **b, int i)
{
	reverse_rotate(a, "a", i);
	reverse_rotate(b, "b", i);
}

void	ss(t_list_d **a, t_list_d **b, int i)
{
	swap(a, "a", i);
	swap(b, "b", i);
}
