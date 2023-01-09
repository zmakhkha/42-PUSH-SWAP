/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:21:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/03 17:01:49 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	int				len;
	char			*tmp;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	tmp = (char *)s;
	i = 0;
	len = ft_strlen(tmp);
	res = (char *)malloc((len + 1) * sizeof (char));
	if (!res)
		return (NULL);
	while (tmp[i])
	{
		res[i] = (*f)(i, tmp[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
