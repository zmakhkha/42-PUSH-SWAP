/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:55:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/10 18:36:43 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_check_input_1(int n, char **table)
{
	int		i;
	char	*tmp;
	char	*str;

	str = ft_strdup("");
	i = 0;
	while (++i < n)
	{
		tmp = ft_strtrim(table[i], " ");
		if (*tmp == '\0')
		{
			free (str);
			free (tmp);
			ft_print_error("Error");
		}
		str = ft_join_free(str, tmp);
		str = ft_join_free(str, ft_strdup(" "));
	}
	return (str);
}

char	**ft_check_input(int n, char **table)
{
	int		i;
	char	*str;
	char	**splited;

	str = ft_check_input_1(n, table);
	splited = ft_split(str, ' ');
	i = -1;
	while (splited[++i])
		ft_isnumber(splited[i]);
	free (str);
	return (splited);
}

int	*ft_check_number_duplicate(int n, char **tab)
{
	int	i;
	int	j;
	int	*int_tab;

	int_tab = (int *)malloc((n + 1) * sizeof(int));
	if (!int_tab)
		ft_print_error("Alocation Failed (ft_check_number_duplicate)");
	i = -1;
	while (++i < n)
	{
		ft_check_overflow(tab[i]);
		int_tab[i] = ft_atoi(tab[i]);
	}
	int_tab[i] = 0;
	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
		{			
			if (int_tab[i] == int_tab[j])
				ft_print_error("Error");
		}
	}
	return (int_tab);
}

void	ft_skip_0(char *a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i] == 48)
		i++;
	j = 0;
	while (a[i + j])
		j++;
	if (j > 12)
		ft_print_error("Error");
}

void	ft_check_overflow(char *a)
{
	ft_skip_0(a);
	if ((long long) INT_MIN >= ft_atoi_long(a) || \
		ft_atoi_long(a) >= (long long)INT_MAX)
		ft_print_error("Error");
}
