/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:48:48 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 20:23:11 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			init_data(t_data *data)
{
	if (!(data->ptr = mlx_init()))
		return (0);
	data->pos_x = 0;
	data->pos_y = 0;
	data->dir_x = 0;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0;
	data->map = 0;
	data->south.ptr = 0;
	data->north.ptr = 0;
	data->east.ptr = 0;
	data->west.ptr = 0;
	data->height = 0;
	data->width = 0;
	data->floor.set = 0;
	data->ceiling.set = 0;
	data->sprite.ptr = 0;
	data->valid = 1;
	data->save = 0;
	data->weapon.ptr = 0;
	data->speed = 1;
	data->life = 1;
	return (1);
}

int			key_pressed(int keycode, void *param)
{
	t_data *data;

	data = (t_data*)param;
	data->x = 0;
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 ||
		keycode == 124 || keycode == 123)
		move(data, keycode);
	else if (keycode == 53)
		closer((void*)data);
	else if (keycode == 257)
		run(data);
	if (keycode == 49)
		shot(data);
	else if (keycode == 14)
		give_money(data);
	else
		ray_casting(data, "textures/sprites/shot1.XPM");
	return (1);
}

int			main(int ac, char **av)
{
	t_data *data;

	if (ac > 1)
	{
		if (!(data = malloc(sizeof(t_data))))
			return (0);
		init_data(data);
		if (!parse_args(av, data))
			return (closer(data));
		if (data->width > 2500)
			data->width = 2500;
		if (data->height > 1300)
			data->height = 1300;
		if (!(data->win = mlx_new_window(data->ptr, data->width, data->height,
			"Cube 3d")) || !ray_casting(data, "textures/sprites/shot1.XPM") ||
			(data->save == 1 && create_bmp(data)))
			return (closer(data));
		mlx_hook(data->win, 2, 0, &key_pressed, data);
		mlx_hook(data->win, 17, 0, &closer, data);
		mlx_loop(data->ptr);
	}
	else
		write(1, "Error\nYou have to provide a least one argument\n", 47);
	return (0);
}
