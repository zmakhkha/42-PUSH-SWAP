/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:55:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/23 18:03:33 by zmakhkha         ###   ########.fr       */
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
	if (number[0] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			ft_print_error("Not a number\n");
		i++;
	}
}

void	ft_check_input(int n, char **table)
{
	int		i;
	char	*tmp;
	char	*str;
	char	**splited;

	str = ft_strdup("");
	i = 0;
	while (++i < n)
	{
		tmp = ft_strtrim(table[i], " ");
		ft_detect_overflow(tmp);
		if (*tmp == '\0')
			ft_print_error("Empty Argument\n");
		str = ft_join_free(str, tmp);
		str = ft_join_free(str, " ");
	}
	splited = ft_split(str, ' ');
	i = -1;
	while (splited[++i])
	{
		ft_isnumber(splited[i]);
	}
}

void	ft_check_number_duplicate(int n, char **tab)
{
	int	i;
	int	j;
	int	*int_tab;

	int_tab = (int *)malloc((n - 1) * sizeof(int));
	if (!int_tab)
		ft_print_error("Alocation Failed (ft_check_number_duplicate)\n");
	i = 1;
	while (i < n)
	{
		int_tab[i - 1] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	while (i < n -1)
	{
		j = i + 1;
		while (j < n)
		{
			if (int_tab[i] == int_tab[j])
				ft_print_error("Duplicated number\n");
			j++;
		}
		i++;
	}
}
