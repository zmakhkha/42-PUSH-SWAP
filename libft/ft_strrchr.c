/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:17:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/26 15:03:10 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	ind;
	int	nbr;

	nbr = ft_strlen((char *)s);
	ind = 0;
	i = 0;
	c = (char)c;
	while (i <= nbr)
	{
		if ((s[i] == c))
			ind = i;
		i++;
	}
	if (s[ind] == c)
		return ((char *)&s[ind]);
	else
		return (NULL);
}
