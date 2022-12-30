/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/30 17:29:01 by zmakhkha         ###   ########.fr       */
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
	ft_parse_it(n, v); 
	
	a = ft_fill_it(v);
	tmp = a;	
	printf("=========>A\n");
	while (tmp)
	{
		printf("%d ->", tmp->content);
		tmp = tmp -> prev;
	}
	printf("\n");
	push(&a, &b,"a");
	push(&a, &b,"a");
	tmp = a;
	printf("=========>A\n");
	while (tmp)
	{
		printf("%d ->", tmp->content);
		tmp = tmp -> prev;
	}
	printf("\n");	
	printf("=========>B\n");
	tmp = b;
	while (tmp)
	{
		printf("%d ->", tmp->content);
		tmp = tmp -> prev;
	}
	printf("\n");	
	ft_free_list_d(&a);
	ft_free_list_d(&b);

}
