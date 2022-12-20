/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:55:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/20 18:23:11 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(int n, char **table)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (ft_isnumber(table[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

//int ft_check_duplicate(int n, char **table)
//{
	
//}

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}
