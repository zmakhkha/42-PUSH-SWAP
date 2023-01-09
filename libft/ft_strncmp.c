/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:30:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/02 15:59:10 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*s01;
	char	*s02;

	s01 = (char *)s1;
	s02 = (char *)s2;
	if (n)
	{
		i = 0;
		while ((s01[i] == s02[i]) && (i < n) && s1[i] && s2[i])
			i++;
		if (i == n)
			return (s01[i - 1] - s02[i - 1]);
		return ((unsigned char)s01[i] - (unsigned char)s02[i]);
	}
	return (0);
}
