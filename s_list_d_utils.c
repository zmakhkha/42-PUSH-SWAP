/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:15:18 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/14 16:53:42 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<push_swap.h>

t_list_d	*ft_lstnew(void *content)
{
	t_list_d	*new;

	new = (t_list_d *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_front(t_list_d **lst, t_list_d **new)
{
	if (lst && new)
	{
		if (*lst)
			(*new)->next = *lst;
	}
	*lst = *new;
}

t_list_d *ft_get_end(t_list_d *list)
{
	if (list)
	{
		while(list -> next)
			list = list ->next;
		return (list);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list_d **lst, t_list_d **back)
{
	if (lst && back)
	{
			(*back) ->prev = *lst;
			(*lst) -> next = *back;
	}
}

