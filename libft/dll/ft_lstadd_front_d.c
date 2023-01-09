/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:58:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/27 17:25:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dll.h"

void	ft_lstadd_front_d(t_list_d **lst, t_list_d *new)
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
