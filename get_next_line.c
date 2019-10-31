/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:20:16 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/29 15:50:23 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		init_gnl(t_gnl **data, int fd)
{
	if (BUFFER_SIZE < 1)
		return (-1);
	if (!(*data = malloc(sizeof(t_gnl))))
		return (0);
	data[0]->i = 0;
	if ((data[0]->res = read(fd, data[0]->buff, BUFFER_SIZE)) < 1)
		return (data[0]->res);
	return (1);
}

int		str_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		re_alloc(int index, t_gnl *data, char **line)
{
	int		len;
	char	*s;
	int		i;

	i = 0;
	len = str_len(*line);
	if (!(s = malloc(sizeof(char) * (len + 2))))
		return (0);
	while (i < len)
	{
		s[i] = line[0][i];
		i++;
	}
	s[i] = data->buff[index];
	s[i + 1] = '\0';
	free(*line);
	*line = s;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl *data = 0;

	if ((!data || data->res == -1) && init_gnl(&data, fd) == -1)
		return (reset_props(&data, 1));
	if (!init_line(line))
		return (0);
	while (data->i < data->res && data->res > 0)
	{
		if (data->buff[data->i] == '\n')
		{
			data->i++;
			if (data->i == data->res)
				re_loop(data, fd);
			return (1);
		}
		if (!re_alloc(data->i++, data, line))
			return (-1);
		if (data->i == data->res)
			re_loop(data, fd);
	}
	return (reset_props(&data, 0));
}
