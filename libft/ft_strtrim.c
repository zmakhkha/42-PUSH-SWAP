/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:50:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/28 15:57:42 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l1;
	int		index;

	if (s1 && set)
	{
		index = 0;
		while (s1[index] && ft_strchr(set, s1[index]))
			index++;
		l1 = ft_strlen((char *)s1);
		if (index == l1)
			return (ft_substr(s1, index, 1));
		while (ft_strchr(set, s1[l1]) && l1)
			l1--;
		return (ft_substr(s1, index, l1 - index + 1));
	}
	return (NULL);
}
