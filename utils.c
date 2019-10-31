/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:56:54 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/29 22:18:51 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_map(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_data(t_data **data)
{
	free(data[0]->ptr);
	free(data[0]->win);
	free(data[0]->north.ptr);
	free(data[0]->south.ptr);
	free(data[0]->east.ptr);
	free(data[0]->west.ptr);
	free(data[0]);
}

void	load_texture_data(t_data *data, char *line)
{
	if (ft_compare("NO./", line) == 0)
		data->north.data = (int*)mlx_get_data_addr(data->north.ptr,
		&data->north.bpp, &data->north.size_l, &data->north.endian);
	else if (ft_compare("SO./", line) == 0)
		data->south.data = (int*)mlx_get_data_addr(data->south.ptr,
		&data->south.bpp, &data->south.size_l, &data->south.endian);
	else if (ft_compare("WE./", line) == 0)
		data->west.data = (int*)mlx_get_data_addr(data->west.ptr,
		&data->west.bpp, &data->west.size_l, &data->west.endian);
	else if (ft_compare("EA./", line) == 0)
		data->east.data = (int*)mlx_get_data_addr(data->east.ptr,
		&data->east.bpp, &data->east.size_l, &data->east.endian);
	else if (ft_compare("S./", line) == 0)
		data->sprite.data = (int*)mlx_get_data_addr(data->sprite.ptr,
		&data->sprite.bpp, &data->sprite.size_l, &data->sprite.endian);
}

int		closer(void *data)
{
	t_data *temp;

	temp = (t_data*)data;
	free_map(temp);
	free_data(&temp);
	exit(EXIT_SUCCESS);
	return (1);
}
