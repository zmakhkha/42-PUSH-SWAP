/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:25:01 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/04 10:51:31 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	c_words(char *tmp, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (tmp[i])
	{
		if (tmp[i] != c && (tmp[i + 1] == c || tmp[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static int	lenght(char *tmp, int i, char c)
{
	int	res;

	res = 0;
	if (c_words(tmp, c))
	{
		while (tmp[i] && tmp[i] != c)
		{
			i++;
			res++;
		}
	}
	return (res);
}

static	char	**free_byte(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free (a);
	return (NULL);
}

char	**ft_split(char	const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		len;

	j = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc((1 + c_words((char *)s, c)) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < c_words((char *)s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		len = lenght((char *)s, j, c);
		res[i] = ft_substr(s, j, len);
		if (!res[i])
			return (free_byte(res));
		j += len;
		i++;
	}
	res[c_words((char *)s, c)] = NULL;
	return (res);
}
