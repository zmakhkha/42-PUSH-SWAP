/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:55:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/09 12:36:14 by zmakhkha         ###   ########.fr       */
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

void	ft_check_overflow(char *a)
{
	if ((unsigned long)ft_atoi(a) != ft_atoi_long(a))
		ft_print_error("Error");
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
