/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:01:51 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/02 16:39:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = ft_strlen(s1);
	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_strlcpy(res, s1, len + 1);
	else
		return (NULL);
	return (res);
}
