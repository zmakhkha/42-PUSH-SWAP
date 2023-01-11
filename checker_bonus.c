/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:23:59 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/10 17:42:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_p2(t_list_d **a, t_list_d **b, char *line)
{
	int	i;

	i = 1;
	if (!ft_strncmp(line, "sa\n", 3))
		swap(a, "a", 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(b, "b", 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(a, b, "b", 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(b, a, "a", 0);
	else
		i = 0;
	return (i);
}	

int	ft_check_p1(t_list_d **a, t_list_d **b, char *line)
{
	int	i;

	i = 1;
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(a, "a", 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b, "b", 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(a, "a", 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(b, "b", 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		i = 0;
	return (i);
}

void	ft_check_sorting(t_list_d *a, t_list_d *b)
{
	if (ft_issorted(a) && !ft_lst_len(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int n, char **v)
{
	t_list_d	*a;
	t_list_d	*b;
	char		*line;

	if (n > 1)
	{
		b = NULL;
		a = ft_parse_it(n, v);
		line = get_next_line(0);
		while (line)
		{
			if (!ft_check_p1(&a, &b, line) && !ft_check_p2(&a, &b, line))
			{
				free (line);
				ft_free_list_d(&a);
				ft_print_error("Error");
			}
			free (line);
			line = get_next_line(0);
		}
		ft_check_sorting(a, b);
		ft_free_list_d(&a);
	}
	return (0);
}
