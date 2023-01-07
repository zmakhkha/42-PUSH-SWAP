/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:04:08 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/07 18:10:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_free(char	*s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free (s1);
	free (s2);
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
	if (!number[i])
	{
		free (number);
		ft_print_error("Maaaachi number\n");
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			free (number);
			ft_print_error("Not a number\n");
		}
		i++;
	}
}

t_list_d	*ft_fill_it(char **args)
{
	int			i;
	t_list_d	*lst;
	t_list_d	*tmp;

	lst = NULL;
	i = 0;
	while (args[++i])
	{
		tmp = ft_lstnew_d(ft_atoi(args[i]));
		ft_lstadd_back_d(&lst, tmp);
	}
	return (lst);
}
