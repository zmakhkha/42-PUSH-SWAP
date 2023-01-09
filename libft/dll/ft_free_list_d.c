/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:53:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/02 19:17:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dll.h"

void	ft_free_list_d(t_list_d **a)
{
	t_list_d	*tmp;

	if (a && *a)
	{	
		if ((*a)-> prev == NULL)
			free ((*a));
		else
		{
			while ((*a)-> prev)
			{
				tmp = *a;
				(*a) = (*a)-> prev;
				free (tmp);
			}
			free ((*a));
		}
	}
}
