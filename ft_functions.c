/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:18:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/02 18:29:40 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
// index the list
void	ft_index_it(t_list_d **list)
{
	int			i;
	t_list_d	*pos;
	t_list_d	*lst;

	if (list && *list)
	{
		i = 0;
		pos = *list;
		lst = *list;
		while (lst)
		{
			i = 0;
			pos = *list;
			while (pos)
			{
				if (lst -> content > pos -> content)
					i++;
				pos = pos -> prev;
			}
			lst -> index = i;
			lst = lst ->prev;
		}
	}
}

void	ft_position_it(t_list_d **lst)
{
	int			i;
	t_list_d	*pos;

	i = 1;
	if (lst && *lst)
	{
		pos = *lst;
		while (pos)
		{
			pos-> position = i;
			i++;
			pos = pos-> prev;
		}
	}
}

int 	ft_lst_len(t_list_d *a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a)
		{
			i++;
			a = a -> prev;
		}
	}
	return (i);
}
//// get the middle of the list
//t_list_d	*ft_get_middle(t_list_d *list)
//{
//	t_list_d	*r1;
//	t_list_d	*r2;

//	if (list)
//	{
//		r1 = list;
//		r2 = list;
//		while (r2)
//		{
//			if (r2 && r2 -> next && r2 -> next)
//			{
//				r2 = r2 -> next ->next;
//				r1 = r1 -> next;
//			}
//		}
//	return (r1);
//	}
//	return (NULL);
//}