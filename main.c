/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/18 18:22:34 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include"push_swap.h"

int main()
{
	t_list_d *new;
	int	i = 5;

	new = ft_lstnew_d(15);
	while(i--)
	{
		ft_lstadd_back_d(&new ,ft_lstnew_d(i*2));
	}
	while (new)
	{
		printf("%d", new->content);
		new = new -> next;
	}
	return (0);
	
}