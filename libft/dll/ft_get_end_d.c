/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_end_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:58:56 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/06 15:19:59 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dll.h"

t_list_d	*ft_get_end_d(t_list_d *list)
{
	t_list_d	*tmp;

	if (list)
	{
		tmp = list;
		while (list -> prev)
		{
			tmp = list;
			list = list ->prev;
		}
		return (tmp -> prev);
	}
	return (NULL);
}
