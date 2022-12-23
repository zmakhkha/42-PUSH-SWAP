/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/23 18:02:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include"push_swap.h"

int main(int n, char **v)
{
	//t_list_d *lst;

	//if (n == 1)
	//	return 0;
	//if (ft_check_input(n, v))
	//{	
	//	lst = ft_fill_it(v);
	//	while (lst)
	//	{
	//		printf("%d ->", lst ->content);
	//		lst = lst ->prev;
	//	}
	//		printf("(null)");
	//	return (1);
	//}
	//else
	//	printf("Error");
	//char **a;

	ft_check_input(n, v);
	ft_check_number_duplicate(n, v);
	ft_detect_overflow("564564564651165156154654");
	return (0);
	
}
