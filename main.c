/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/27 17:45:18 by zmakhkha         ###   ########.fr       */
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
	//atexit(CheckLeks);
	ft_parse_it(n, v);
	t_list_d *lst;
	t_list_d *tmp;
	
	 lst = ft_fill_it(v);
	 tmp = lst;
	 while (tmp)
	 {
		printf("%d\n", tmp->content);
		tmp = tmp -> prev;
	 }
	printf("===========\n");
	swap(&lst, "a");
	while (lst -> prev)
	 {
		printf("%d\n", lst->content);
		lst = lst -> prev;
	 }
	printf("===========\n");
	 while (lst)
	 {
		printf("%d\n", lst->content);
		lst = lst -> next;
	 }
	//while (tmp)
	// {
	//	printf("%d\n", lst->content);
	//	//tmp = lst;
	//	tmp = tmp -> prev;
	//	//free(tmp);
	// }
}
