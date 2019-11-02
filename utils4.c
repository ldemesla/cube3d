/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:24:01 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 17:09:46 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		check_info(t_data *data)
{
	if (data->width == -1 || data->height == -1)
		write(1, "Error\nYou need to provide a resolution\n", 39);
	else if (!data->west.ptr || !data->east.ptr || !data->north.ptr
	|| !data->south.ptr || !data->sprite.ptr)
		write(1, "Error\nWrong texture path\n", 25);
	else if (!data->map)
		write(1, "Error\nYou need to provide a map\n", 32);
	else if (!data->ceiling.set || !data->floor.set)
		write(1, "Error\nNo color for ceilling or floor\n", 37);
	else if (!data->valid || !check_last(data))
		write(1, "Error\nInvalid map\n", 18);
	else if (data->pos_x == 0 && data->pos_y == 0)
		write(1, "Error\nYou need to provide a spawn point\n", 40);
	else
		return (1);
	return (0);
}

int		check_end_line(char *line, int nb)
{
	while (*line == ' ')
		line++;
	line++;
	while (nb > 0 && *line)
	{
		if (*line == ' ' || *line == ',')
			line++;
		if (*line <= '9' && *line >= '0')
		{
			nb--;
			while (*line <= '9' && *line >= '0' && *line)
				line++;
		}
	}
	while (*line)
	{
		if (*line != ' ')
		{
			write(1, "Error\nIncorrect data\n", 21);
			return (0);
		}
		line++;
	}
	return (1);
}
