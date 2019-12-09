/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:58:40 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 20:13:54 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_color_and_resolution(char *line, t_data *data)
{
	if (ft_compare("F", line) == 0 && check_end_line(line, 3))
	{
		data->floor.R = get_number(line, 1);
		data->floor.G = get_number(line, 2);
		data->floor.B = get_number(line, 3);
		if (data->floor.B >= 0 && data->floor.G >= 0 && data->floor.R >= 0)
			data->floor.set = 1;
	}
	else if (ft_compare("C", line) == 0 && check_end_line(line, 3))
	{
		data->ceiling.R = get_number(line, 1);
		data->ceiling.G = get_number(line, 2);
		data->ceiling.B = get_number(line, 3);
		if (data->ceiling.B >= 0 && data->ceiling.G >= 0 &&
		data->ceiling.R >= 0)
			data->ceiling.set = 1;
	}
	else if (ft_compare("R", line) == 0 && check_end_line(line, 2))
	{
		data->width = get_number(line, 1);
		data->height = get_number(line, 2);
	}
	else
		return (0);
	return (1);
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
	if (is_loaded(line, data))
		load_texture_data(data, line);
}

int		get_map(char *line, t_data *data)
{
	static int	nb = 0;
	int			i;
	char		*temp;

	i = -1;
	if (nb == 0)
		data->map_width = ft_strlen_map(line);
	if (!(temp = remove_space(line)))
		return (0);
	while (temp[++i] && data->valid == 1)
	{
		if (temp[0] != '1' || temp[data->map_width - 1] != '1' ||
			(temp[i] != '1' && nb == 0) || (temp[i] != '0' && temp[i] != '1' &&
			temp[i] != '2' && temp[i] != 'N' && temp[i] != 'S' &&
			temp[i] != 'W' && temp[i] != 'E'))
			data->valid = 0;
		if ((temp[i] == 'N' || temp[i] == 'S' || temp[i] == 'W' ||
		temp[i] == 'E') && set_pos(data, temp[i], i))
			temp[i] = '0';
	}
	if (!add_line(data, temp, nb))
		return (0);
	return ((nb = nb + 1));
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
	{
		if (!(get_color_and_resolution(line, data)))
			return (0);
	}
	else if (line[0] == '1' && !(get_map(line, data)))
		return (0);
	if (line[0] == '0')
	{
		write(1, "Error\nMap need to be surrounded by walls\n", 41);
		return (0);
	}
	if (line[0] != '\n' && line[0] != 'N' && line[0] != 'S' && line[0] !=
	'E' && line[0] != 'W' && line[0] != 'R' && line[0] != 'C' && line[0] != 'F'
	&& line[0] != '1' && line[0] != '\0')
		write(1, "Error\nIncorrect data\n", 21);
	else
		return (1);
	return (0);
}

int		parse_args(char **av, t_data *data)
{
	int		fd;
	char	*line;

	if ((fd = check_extension(av[1])) < 0)
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
	if (!check_info(data))
		return (0);
	if (av[2] && ft_strncmp(av[2], "--save", 6) == 0 && ft_strlen(av[2]) == 6)
		data->save = 1;
	return (1);
}
