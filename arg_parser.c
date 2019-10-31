/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:58:40 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/29 17:29:09 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_color_and_resolution(char *line, t_data *data)
{
	if (ft_compare("F", line) == 0)
	{
		data->floor.R = get_number(line, 1);
		data->floor.G = get_number(line, 2);
		data->floor.B = get_number(line, 3);
		if (data->floor.B >= 0 && data->floor.G >= 0 && data->floor.R >= 0)
			data->floor.set = 1;
	}
	else if (ft_compare("C", line) == 0)
	{
		data->ceiling.R = get_number(line, 1);
		data->ceiling.G = get_number(line, 2);
		data->ceiling.B = get_number(line, 3);
		if (data->ceiling.B >= 0 && data->ceiling.G >= 0 &&
		data->ceiling.R >= 0)
			data->ceiling.set = 1;
	}
	else if (ft_compare("R", line) == 0)
	{
		data->width = get_number(line, 1);
		data->height = get_number(line, 2);
	}
}

void	get_textures(char *line, t_data *data)
{
	if (ft_compare("NO./", line) == 0)
		data->north.ptr = mlx_xpm_file_to_image(data->ptr, to_file(line, '/'),
		&data->north.width, &data->north.height);
	else if (ft_compare("SO./", line) == 0)
		data->south.ptr = mlx_xpm_file_to_image(data->ptr, to_file(line, '/'),
		&data->south.width, &data->south.height);
	else if (ft_compare("WE./", line) == 0)
		data->west.ptr = mlx_xpm_file_to_image(data->ptr, to_file(line, '/'),
		&data->west.width, &data->west.height);
	else if (ft_compare("EA./", line) == 0)
		data->east.ptr = mlx_xpm_file_to_image(data->ptr, to_file(line, '/'),
		&data->east.width, &data->east.height);
	else if (ft_compare("S./", line) == 0)
		data->sprite.ptr = mlx_xpm_file_to_image(data->ptr, to_file(line, '/'),
		&data->sprite.width, &data->sprite.height);
	load_texture_data(data, line);
}

int		get_map(char *line, t_data *data)
{
	static int	nb = 0;
	int			i;
	char		*temp;

	i = 0;
	if (nb == 0)
		data->map_width = ft_strlen_map(line);
	temp = remove_space(line);
	if (temp == 0)
		return (0);
	while (temp[i] && data->valid == 1)
	{
		if (temp[0] != '1' || temp[data->map_width - 1] != '1' ||
			(temp[i] != '1' && nb == 0) || temp[i] > '2' || temp[i] < '0')
			data->valid = 0;
		i++;
	}
	if (data->valid == 1)
		if (!add_line(data, temp, nb))
			return (0);
	nb++;
	return (1);
}

int		parse_infos(t_data *data, char *line)
{
	while (*line == ' ' && *line)
		line++;
	if ((line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E') && data->map == 0)
		get_textures(line, data);
	else if ((line[0] == 'F' || line[0] == 'C' || line[0] == 'R') &&
			data->map == 0)
		get_color_and_resolution(line, data);
	else if (line[0] == '1')
		if (!(get_map(line, data)))
			return (0);
	return (1);
}

int		parse_args(char **av, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	if (ft_strncmp(av[i], "-save", 5) == 0 && ft_strlen(av[1]) == 5 &&
		(data->save = 1))
		i++;
	if ((fd = check_extension(av[i])) < 0)
		return (0);
	while (get_next_line(fd, &line) && data->valid == 1)
	{
		if (!parse_infos(data, line))
			return (0);
		free(line);
	}
	if (!(parse_infos(data, line)))
		return (0);
	free(line);
	if (!data->width || !data->height || !data->west.ptr || !data->east.ptr
	|| !data->north.ptr || !data->south.ptr || !data->map || !data->ceiling.set
	|| !data->floor.set || !data->valid || !check_last(data))
		return (0);
	return (1);
}
