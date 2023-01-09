/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/09 09:32:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_size_len(const char *a, int b);
int		found_new_line(char *a);
char	*fill_buffer(int fd, char *buff, int *size);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
void	get_last(char **buff, char **line, int i);

#endif
