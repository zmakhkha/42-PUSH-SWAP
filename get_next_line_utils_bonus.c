/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/09 09:13:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*p1;
	size_t	i;

	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	p1 = (char *)p;
	while (i < size * count)
	{
		*(p1 + i) = '\0';
		i++;
	}
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	if (len != 0)
	{
		i = 0;
		len--;
		while (src[i] && i < len)
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_calloc(1, 1));
	if (len > size - start)
		len = size - start;
	t = (char *)malloc(sizeof(char) * len + 1);
	if (!t)
		return (NULL);
	if (start < ft_strlen(s) && s[start])
		ft_strlcpy(t, s + start, len + 1);
	else
		*t = 0;
	return (t);
}

void	get_last(char **buff, char **line, int i)
{
	if (i)
	{
		if (ft_strlen(*buff))
			*line = ft_substr(*buff, 0, ft_strlen(*buff));
		else
			*line = NULL;
	}
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
}
