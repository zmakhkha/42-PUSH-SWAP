/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:55:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/24 16:11:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (*tmp == '\0')
			ft_print_error("Empty Argument\n");
		str = ft_join_free(str, tmp);
		str = ft_join_free(str, " ");
	}
	splited = ft_split(str, ' ');
	i = -1;
	while (splited[++i])
		ft_isnumber(splited[i]);
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
		ft_check_overflow(tab[i]);
		int_tab[i - 1] = ft_atoi(tab[i]);
		i++;
	}
	i = -1;
	while (++i < n -1)
	{
		j = i + 1;
		while (j < n)
		{
			if (int_tab[i] == int_tab[j])
				ft_print_error("Duplicated number\n");
			j++;
		}
	}
}

void	ft_check_overflow(char *a)
{
	if ((unsigned long)ft_atoi(a) != ft_atoi_long(a))
		ft_print_error("Overflow wla Underflow\n");
}

void	ft_parse_it(int n, char **v)
{
	ft_check_input(n, v);
	ft_check_number_duplicate(n, v);
}
