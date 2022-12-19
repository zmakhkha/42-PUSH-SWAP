/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/19 19:18:03 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include"push_swap.h"

int main(int n, char **v)
{
	t_list_d *lst;

	(void )n;
	if (ft_check_input(v))
	{		
		lst = ft_fill_it(v);
		while (lst)
		{
			printf("%d", lst ->content);
			lst = lst ->prev;
		}
		return (1);
	}
	return (0);
	
}