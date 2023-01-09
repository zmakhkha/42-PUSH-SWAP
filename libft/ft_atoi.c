/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:21:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/02 16:55:29 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ret_nbr(char *tmp)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isdigit(tmp[i]))
	{
		res += tmp[i] - 48 ;
		if (ft_isdigit(tmp[i + 1]))
			res = res * 10;
		if (!ft_isdigit(tmp[i + 1]))
			return (res);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *) str;
	i = 0;
	while ((tmp[i] >= 9 && tmp[i] <= 13) || tmp[i] == 32)
		i++;
	if (ft_isdigit(tmp[i]))
		return (ret_nbr(tmp + i));
	if (((tmp[i] == '+') || (tmp[i] == '-')) && ft_isdigit(tmp[i +1]))
	{
		if (tmp[i] == '-' && ft_isdigit(tmp[i + 1]))
			return (-1 * ret_nbr(tmp + i + 1));
		else if (tmp[i] == '+')
			return (ret_nbr(tmp + i + 1));
		else
			return (0);
	}
	return (0);
}
