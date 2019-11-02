/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:48:48 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 17:10:28 by ldemesla         ###   ########.fr       */
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
	return (1);
}

int			key_pressed(int keycode, void *param)
{
	t_data *data;

	data = (t_data*)param;
	data->x = 0;
	if (keycode == 13)
		move_up(data);
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 0)
		move_left(data);
	else if (keycode == 2)
		move_right(data);
	else if (keycode == 124)
		rotate_right(data);
	else if (keycode == 123)
		rotate_left(data);
	else if (keycode == 53)
		closer((void*)data);
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
		if (!(data->win = mlx_new_window(data->ptr, data->width, data->height,
			"Cube 3d")))
			return (0);
		if (!ray_casting(data, "textures/sprites/shot1.XPM"))
			return (0);
		mlx_hook(data->win, 2, 0, &key_pressed, data);
		mlx_hook(data->win, 17, 0, &closer, data);
		mlx_loop(data->ptr);
	}
	else
		write(1, "Error\nYou have to provide a least one argument\n", 47);
	return (0);
}
