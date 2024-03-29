/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:55:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/10 17:55:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char			**ft_remove_spaces(int n, char **table);
char			*ft_join_free(char	*s1, char *s2);
char			**ft_check_input(int n, char **table);
void			ft_isnumber(char *number);
int				*ft_check_number_duplicate(int n, char **tab);
void			ft_print_error(char *err);
void			ft_check_overflow(char *a);
t_list_d		*ft_parse_it(int n, char **v);

void			ft_index_it(t_list_d **list);
int				ft_lst_len(t_list_d *a);

void			ft_sort_tree(t_list_d **a, char *c);
void			ft_sort_four(t_list_d **a, t_list_d **b);
t_list_d		*ft_get_min(t_list_d *a);
int				ft_issorted(t_list_d *lst);
void			ft_position_it(t_list_d **lst);
void			ft_sort_five(t_list_d **a, t_list_d **b);
void			push_to_b(t_list_d **a, t_list_d **b);
void			ft_push_it_back(t_list_d **a, t_list_d **b);
int				ft_get_range(t_list_d *a);
void			push_to_b(t_list_d **a, t_list_d **b);
t_list_d		*ft_get_max(t_list_d *a);
void			ft_push_it_back(t_list_d **a, t_list_d **b);
void			ft_sort_all(t_list_d **a, t_list_d **b);

t_list_d		*ft_fill_it(int *args, int n);

int				ft_get_range(t_list_d *a);
void			swap(t_list_d **a, char *c, int i);
void			push( t_list_d **src, t_list_d **dst, char *c, int i);
void			rotate(t_list_d **a, char *c, int i);
void			reverse_rotate(t_list_d **a, char *c, int i);
void			ft_del_one(t_list_d **lst, int a);
void			rrr(t_list_d **a, t_list_d **b, int i);
void			rr(t_list_d **a, t_list_d **b, int i);
void			ss(t_list_d **a, t_list_d **b, int i);

void			ft_pro_swap(t_list_d **a, t_list_d **b, int i);
void			ft_pro_rotate(t_list_d **a, t_list_d **b, int i);
void			ft_pro_rrotate(t_list_d **a, t_list_d **b, int i);

#endif