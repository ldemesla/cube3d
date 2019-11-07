/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:19:36 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 15:03:39 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move(t_data *data, int keycode)
{
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
	if (data->life <= 0)
		closer(data);
}

void	move_up(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->dir_x)]
		[(int)(data->pos_y + data->dir_y)] == 0)
	{
		data->pos_x += (data->dir_x * (0.1 * data->speed));
		data->pos_y += (data->dir_y * (0.1 * data->speed));
	}
	if (data->map[(int)(data->pos_x + data->dir_x)]
		[(int)(data->pos_y + data->dir_y)] == 2)
		data->life -= 0.1;
}

void	move_down(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->dir_x)]
		[(int)(data->pos_y - data->dir_y)] == 0)
	{
		data->pos_x -= (data->dir_x * (0.1 * data->speed));
		data->pos_y -= (data->dir_y * (0.1 * data->speed));
	}
	if (data->map[(int)(data->pos_x - data->dir_x)]
		[(int)(data->pos_y - data->dir_y)] == 2)
		data->life -= 0.1;
}

void	rotate_left(t_data *data)
{
	double temp;

	temp = data->dir_x;
	data->dir_x = temp * cos(-0.0875 * 2) - data->dir_y * sin(-0.0875 * 2);
	data->dir_y = temp * sin(-0.0875 * 2) + data->dir_y * cos(-0.0875 * 2);
	temp = data->plane_x;
	data->plane_x = temp * cos(-0.0875 * 2) - data->plane_y * sin(-0.0875 * 2);
	data->plane_y = temp * sin(-0.0875 * 2) + data->plane_y * cos(-0.0875 * 2);
}

void	rotate_right(t_data *data)
{
	double temp;

	temp = data->dir_x;
	data->dir_x = temp * cos(0.0875 * 2) - data->dir_y * sin(0.0875 * 2);
	data->dir_y = temp * sin(0.0875 * 2) + data->dir_y * cos(0.0875 * 2);
	temp = data->plane_x;
	data->plane_x = temp * cos(0.0875 * 2) - data->plane_y * sin(0.0875 * 2);
	data->plane_y = temp * sin(0.0875 * 2) + data->plane_y * cos(0.0875 * 2);
}
