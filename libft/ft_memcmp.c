/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:45:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/02 11:26:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s01;
	unsigned char	*s02;
	size_t			i;

	if (s1 == s2)
		return (0);
	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s01[i] == s02[i]))
		i++;
	if (i == n)
		return (s01[i - 1] - s02[i - 1]);
	return (s01[i] - s02[i]);
}
