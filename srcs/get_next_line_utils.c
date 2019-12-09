/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:47:05 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/27 13:19:06 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		re_loop(t_gnl *data, int fd)
{
	data->i = 0;
	if (!(data->res = read(fd, data->buff, BUFFER_SIZE)))
		return (0);
	return (1);
}

int		init_line(char **line)
{
	if (!(*line = malloc(sizeof(char))))
		return (0);
	**line = '\0';
	return (1);
}

int		reset_props(t_gnl **data, int i)
{
	int res;

	res = data[0]->res;
	free(*data);
	*data = 0;
	if (i == 1)
		return (res);
	return (0);
}
