/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:04:08 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/24 16:07:20 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_free(char	*s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free (s1);
	return (res);
}

void	ft_print_error(char *err)
{
	write(1, err, ft_strlen(err));
	exit(1);
}

void	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-' || number[0] == '+')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			ft_print_error("Not a number\n");
		i++;
	}
}
