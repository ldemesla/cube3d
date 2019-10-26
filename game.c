/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:48:48 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/26 18:03:16 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_data(t_data *data)
{
	if (!(data->ptr = mlx_init()))
		return (0);
	if (!(data->win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "Cube 3d")))
		return (0);
	data->pos_x = 4;
	data->pos_y = 4;
	data->dir_x = -1;
	data->dir_y = 1;
	data->plane_x = 0.33;
	data->plane_y = 0.33;
	return (1);
}

int		key_pressed(int keycode, void *param)
{
	t_data *data;
	data = (t_data*)param;
	data->x = 0;
	if (keycode == 13)
		move_up(data);
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 2)
		rotate_right(data);
	else if (keycode == 0)
		rotate_left(data);
	ray_casting(data);
	return (1);
}

int	main(void)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		return (0);
	init_data(data);
	if (!ray_casting(data))
		return (0);
	mlx_key_hook(data->win, &key_pressed, data);
	mlx_loop(data->ptr);
	return (0);
}
