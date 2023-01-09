/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:36 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/08 19:14:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_size_len(const char *a, int b)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	if (b)
	{
		while (a[i] && a[i] != '\n')
			i++;
		return (i);
	}
	else
	{
		while (a[i])
			i++;
		return (i);
	}
}

char	*fill_buffer(int fd, char *buff, int *size)
{
	int		i[2];
	char	*tmp;
	char	*res;

	tmp = ft_calloc(1, BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buff), NULL);
	*size = read(fd, tmp, BUFFER_SIZE);
	i[1] = ft_strlen(buff);
	i[0] = -1;
	if (*size == -1)
		return (NULL);
	if (*size == 0)
		return (free(tmp), buff);
	res = ft_calloc(1, *size + i[1] + 1);
	if (!res)
		return (free(tmp), free(buff), NULL);
	while (++i[0] < i[1])
		res[i[0]] = buff[i[0]];
	res[i[0]] = 0;
	i[0] = -1;
	while (tmp[++i[0]])
		res[i[1] + i[0]] = tmp[i[0]];
	res[i[1] + i[0]] = 0;
	return (free(tmp), free(buff), res);
}

char	*update_buffer(char *buff)
{
	char	*res;
	int		lign_index;

	lign_index = ft_size_len(buff, 1) + 1;
	res = ft_substr(buff, lign_index, ft_strlen(buff));
	free(buff);
	return (res);
}

int	found_new_line(char *a)
{
	int	i;

	i = 0;
	while (a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			_size;
	int			new_line_index;

	line = NULL;
	_size = BUFFER_SIZE;
	if (!buff)
		buff = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0))
		return (get_last(&buff, NULL, 0), NULL);
	while (!found_new_line(buff) && _size != 0)
		buff = fill_buffer(fd, buff, &_size);
	if (found_new_line(buff))
	{
		new_line_index = ft_size_len(buff, 1);
		line = ft_substr(buff, 0, new_line_index + 1);
		buff = update_buffer(buff);
	}
	else if (_size == 0)
		get_last(&buff, &line, 1);
	return (line);
}
