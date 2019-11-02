/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:32:53 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 17:24:01 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_number(char *line, int index)
{
	int i;
	int	count;
	int	nb;
	int	size;

	i = 0;
	count = 0;
	size = ft_strlen(line) + 1;
	line = to_file(line, 'R');
	while (i < size && line[i])
	{
		nb = 0;
		if (line[i] != ' ' && line[i] != ',' && line[i] < '0' && line[i] > '9')
			return (-1);
		while (line[i] == ' ' || line[i] == ',')
			i++;
		if ((line[i] < '0' || line[i] > '9'))
			return (-1);
		while (line[i] >= '0' && line[i] <= '9' && line[i])
			nb = nb * 10 + (line[i++] - 48);
		count++;
		if (count == index)
			return (nb);
	}
	if (count != index)
		return (-1);
	return (nb);
}

int		**copy_map(t_data *data, int lines)
{
	int i;
	int o;
	int	**temp;

	i = 0;
	if (!(temp = malloc(sizeof(int*) * (lines + 1))))
		return (0);
	while (i < lines + 1)
	{
		if (!(temp[i] = malloc(sizeof(int) * data->map_width)))
			return (0);
		i++;
	}
	i = 0;
	while (i < lines)
	{
		o = 0;
		while (o < data->map_width)
		{
			temp[i][o] = data->map[i][o];
			o++;
		}
		i++;
	}
	return (temp);
}

int		add_line(t_data *data, char *line, int nb)
{
	int i;
	int **temp;

	i = 0;
	if (!(temp = copy_map(data, nb)))
		return (0);
	while (i < data->map_width)
	{
		temp[nb][i] = line[i] - 48;
		i++;
	}
	i = 0;
	if (nb > 0)
	{
		while (i < nb)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	data->map_height = nb + 1;
	data->map = temp;
	return (1);
}

int		check_last(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map_width)
	{
		if (data->map[data->map_height - 1][i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_strlen_map(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (((line[i] >= '0' && line[i] <= '4') || line[i] == 'N' || line[i] ==
		'S' || line[i] == 'W' || line[i] == 'E') && line[i])
			count++;
		i++;
	}
	return (count);
}
