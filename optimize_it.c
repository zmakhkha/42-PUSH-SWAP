/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:36:27 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/06 19:21:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_pro_swap(t_list_d **a, t_list_d **b, int i)
{
	if (!i)
	{
		if ((*b) ->index < (*b)-> prev->index)
			ss(a, b);
		else
			swap(a, "a");
	}
	else
	{
		if ((*a) ->index > (*a)-> prev->index)
			ss(a, b);
		else
			swap(b, "b");
	}
}

void	ft_pro_rotate(t_list_d **a, t_list_d **b, int i)
{

	if (!i)
	{
		
		if ((*b) ->index < ft_get_end_d(*b)->index)
			rr(a, b);
		else
			rotate(a, "a");
	}
	else
	{
		if ((*a) ->index > ft_get_end_d(*a)->index)
			rr(a, b);
		else
			rotate(b, "b");
	}
}

void	ft_pro_rrotate(t_list_d **a, t_list_d **b, int i)
{

	if (!i)
	{
		
		if ((*b) ->index < ft_get_end_d(*b)->index)
			rrr(a, b);
		else
			reverse_rotate(a, "a");
	}
	else
	{
		if ((*a) ->index > ft_get_end_d(*a)->index)
			rrr(a, b);
		else
			reverse_rotate(b, "b");
	}
}