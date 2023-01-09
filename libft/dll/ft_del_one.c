/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:00:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/26 17:52:16 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dll.h"

void	ft_del_one(t_list_d **lst, int a)
{
	t_list_d	*tmp;

	if (!a && lst)
	{
		tmp = *lst;
		*lst = (*lst)-> prev;
		free (tmp);
	}
	else if (a && lst)
	{
		tmp = ft_get_end_d(*lst);
		tmp -> next -> prev = NULL;
		free (tmp);
	}
}
