/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:55:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/09 12:34:03 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H

# include <stdlib.h>
# include <stdio.h>

typedef struct d_node
{
	struct d_node	*prev;
	struct d_node	*next;
	int				position;
	int				index;
	int				content;
}	t_list_d;

void			ft_lstadd_front_d(t_list_d **lst, t_list_d *new);
void			ft_lstadd_back_d(t_list_d **lst, t_list_d *back);
void			ft_free_list_d(t_list_d **a);
t_list_d		*ft_get_end_d(t_list_d *list);
t_list_d		*ft_fill_it(int *args, int n);
t_list_d		*ft_lstnew_d(int content);

#endif