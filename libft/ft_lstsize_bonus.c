/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:57:46 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/29 17:53:45 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*pos;
	int		i;

	if (lst)
	{
		i = 1;
		pos = lst;
		while (pos->next)
		{
			pos = pos->next;
			i++;
		}
		return (i);
	}
	return (0);
}
