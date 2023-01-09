/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:07:14 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/24 21:27:34 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	if (s[i] == c)
		return ((char *) &s[i]);
	if (s[i] == '\0')
		return (NULL);
	return (NULL);
}
