/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:59:14 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/03 17:22:27 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	s1;
	size_t	s2;
	size_t	res;

	if (!dst && !len)
		return (0);
	s1 = ft_strlen(dst);
	s2 = ft_strlen(src);
	if (len <= s1)
		return (s2 + len);
	i = 0;
	if (dst && src && len)
	{
		while (i < s2 && i < len - s1 -1)
		{
			dst[s1 + i] = src[i];
			i++;
		}
	}
	dst[s1 + i] = '\0';
	res = s1 + s2;
	return (res);
}
