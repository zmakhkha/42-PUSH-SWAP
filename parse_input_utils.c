/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:04:08 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/10 18:32:08 by zmakhkha         ###   ########.fr       */
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
	write(1, "\n", 1);
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
		ft_print_error("Error");
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			free (number);
			ft_print_error("Error");
		}
		i++;
	}
}

t_list_d	*ft_fill_it(int *args, int n)
{
	int			i;
	t_list_d	*lst;
	t_list_d	*tmp;

	lst = NULL;
	i = 0;
	while (i < n)
	{
		tmp = ft_lstnew_d(args[i]);
		ft_lstadd_back_d(&lst, tmp);
		i++;
	}
	return (lst);
}

t_list_d	*ft_parse_it(int n, char **v)
{
	char		**a;
	int			*t;
	int			i;
	t_list_d	*lst;

	a = ft_check_input(n, v);
	n = 0;
	while (a[n])
		n++;
	t = ft_check_number_duplicate(n, a);
	lst = ft_fill_it(t, n);
	i = 0;
	while (a[i])
	{
		free (a[i]);
		i++;
	}
	free (a);
	free (t);
	return (lst);
}
