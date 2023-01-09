/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:32:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/10/23 11:38:03 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b1;
	size_t	i;

	c = (unsigned char)c;
	b1 = (char *)b;
	i = 0;
	while (i < len)
	{
		*(b1 + i) = c;
		i++;
	}
	return (b1);
}
