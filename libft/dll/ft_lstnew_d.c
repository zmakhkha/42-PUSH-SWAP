/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:53:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/26 17:58:47 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dll.h"

t_list_d	*ft_lstnew_d(int content)
{
	t_list_d	*new;

	new = (t_list_d *) malloc(sizeof(t_list_d));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	new -> prev = NULL;
	new -> position = 0;
	new -> index = 0;
	return (new);
}
