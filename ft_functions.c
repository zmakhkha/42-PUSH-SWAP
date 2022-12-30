/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:18:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/30 16:16:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
// index the list
void	ft_index_it(t_list_d **list)
{
	int	i;

	i = 0;
	if(list)
	{
		while (*list)
		{
			(*list) -> position = i;
		}
		(*list) = (*list) -> next;
		i++;
	}
}
// get the middle of the list
t_list_d	*ft_get_middle(t_list_d *list)
{
	t_list_d	*r1;
	t_list_d	*r2;

	if (list)
	{
		r1 = list;
		r2 = list;
		while (r2)
		{
			if (r2 && r2 -> next && r2 -> next)
			{
				r2 = r2 -> next ->next;
				r1 = r1 -> next;
			}
		}
	return (r1);
	}
	return (NULL);
}
t_list_d	*ft_fill_it(char **args)
{
	int			i;
	t_list_d	*lst;
	t_list_d	*tmp;

	lst = NULL;
	i = 0;
	while (args[++i])
	{
		tmp = ft_lstnew_d(ft_atoi(args[i]));
		ft_lstadd_back_d(&lst, tmp);
	}
	return (lst);
}