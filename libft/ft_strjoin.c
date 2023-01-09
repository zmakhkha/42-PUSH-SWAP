/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:11:22 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/29 10:22:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*k;

	if (!s1 || !s2)
		return (NULL);
	k = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!k)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		k[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		k[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	k[i] = '\0';
	return (k);
}
