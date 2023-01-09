/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:20:04 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/31 19:43:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	char				*d;
	char				*s;

	i = 0;
	d = (char *) dst;
	s = (char *) src;
	if (!dst && !src)
		return (NULL);
	if (n > 0)
	{
		while (i < n)
		{
			d[i] = (unsigned char)s[i];
			i++;
		}
	}
	return (dst);
}
