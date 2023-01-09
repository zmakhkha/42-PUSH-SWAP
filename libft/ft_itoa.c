/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:23:04 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/03 16:30:44 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	get_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*get_limits(int n)
{
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*res;

	res = get_limits(n);
	if (res == NULL)
	{
		i = get_size(n);
		res = (char *)malloc((i + 1) * sizeof(char));
		if (!res)
			return (NULL);
		j = i - 1;
		if (n < 0)
		{
			res[0] = '-';
			n = n * -1;
		}
		while (n > 0)
		{
			res[j--] = '0' + (int)n % 10;
			n /= 10;
		}
		res[i] = 0;
	}
	return (res);
}
