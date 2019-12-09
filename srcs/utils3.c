/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:27:48 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 14:37:20 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	clear_ray(t_ray **ray)
{
	t_sprite *temp;
	t_sprite *temp2;

	temp = ray[0]->sprite;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp);
	}
	free(*ray);
}

void	free_tab(char ***tab)
{
	int i;

	i = 0;
	while (i < 3)
		free(tab[0][i++]);
	free(tab[0]);
}

int		set_sprite(t_data *data)
{
	static int	count = 0;
	char		*line;
	int			i;
	int			fd;

	i = -1;
	fd = open("sprite_anim.txt", O_RDONLY);
	while (get_next_line(fd, &line) && ++i < count)
		free(line);
	data->sprite.ptr = mlx_xpm_file_to_image(data->ptr, line,
	&data->sprite.width, &data->sprite.height);
	data->sprite.data = (int*)mlx_get_data_addr(data->sprite.ptr,
	&data->sprite.bpp, &data->sprite.size_l, &data->sprite.endian);
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	close(fd);
	count++;
	if (count == 3)
		count = 0;
	return (1);
}

int		init(t_ray **ray, t_data **data)
{
	if (!(ray[0] = malloc(sizeof(t_ray))))
		return (0);
	if (!(data[0]->img.ptr = mlx_new_image(data[0]->ptr, data[0]->width,
	data[0]->height)))
		return (0);
	if (!(data[0]->img.data = (int*)mlx_get_data_addr(data[0]->img.ptr,
	&data[0]->img.bpp, &data[0]->img.size_l, &data[0]->img.endian)))
		return (0);
	if (!set_sprite(data[0]))
		return (0);
	return (1);
}

void	give_money(t_data *data)
{
	static int count = 0;

	if (count == 0)
		ray_casting(data, "textures/sprites/money.xmp");
	else
		ray_casting(data, "textures/sprites/shot1.XPM");
	count++;
	if (count == 2)
		count = 0;
}
