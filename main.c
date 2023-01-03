/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/03 19:21:01 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "push_swap.h"

void CheckLeks()
{
	system("leaks push_swap");
}

int main(int n, char **v)
{
	t_list_d *a;
	t_list_d *tmp;
	t_list_d *b;
	
	//atexit(CheckLeks);
	ft_parse_it(n, v); 
	a = ft_fill_it(v);
	//b = a;
	tmp = a;

	//printf("----------->%d\n", ft_get_min(a)->position);

	//tmp = a;
	ft_position_it(&tmp);
	ft_index_it(&tmp);
	////printf("----------->%d\n", ft_get_min(a)->position);
	////printf("=========>A\n");
	////printf("-P- \t -V- \t -I-\n");
	
	//while (tmp)
	//{
	//	printf(" %d \t  %d \t  %d\n",tmp->position, tmp->content, tmp->index);
	//	tmp = tmp -> prev;
	//}
	ft_sort_five(&a, &b);
	//tmp = a;
	//printf("\nafter being soooooorted\n\n");
	//while (tmp) 
	//{
	//	printf(" %d \t  %d \t  %d\n",tmp->position, tmp->content, tmp->index);
	//	tmp = tmp -> prev;
	//}
	//printf("========>%d", ft_issorted(a));
	//printf("\n");
	//printf("\n");
	//ft_free_list_d(&b);
	ft_free_list_d(&a);
	//ft_free_list_d(&tmp);
	return (0);
}
