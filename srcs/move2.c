/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:51:41 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 21:06:07 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		can_walk(int x, int y, t_data *data)
{
	if (data->map[x][y] == 1 || data->map[x][y] == 2)
		return (0);
	else
		return (1);
}

void	move_right(t_data *data)
{
	if (can_walk((int)(data->pos_x + (data->plane_x * 0.2)),
		(int)(data->pos_y - (data->plane_y * 0.2)), data))
	{
		data->pos_x += (data->plane_x * 0.1);
		data->pos_y += (data->plane_y * 0.1);
	}
	if (data->map[(int)(data->pos_x + data->plane_x * data->speed * 0.2)]
		[(int)(data->pos_y - data->plane_y * data->speed * 0.2)] == 2)
		data->life -= 0.1;
}

void	move_left(t_data *data)
{
	if (can_walk((int)(data->pos_x - (data->plane_x * 0.2)),
		(int)(data->pos_y - (data->plane_y * 0.2)), data))
	{
		data->pos_x -= (data->plane_x * 0.1);
		data->pos_y -= (data->plane_y * 0.1);
	}
	if (data->map[(int)(data->pos_x - data->plane_x * data->speed * 0.2)]
		[(int)(data->pos_y - data->plane_y * data->speed * 0.2)] == 2)
		data->life -= 0.1;
}

void	run(t_data *data)
{
	static int count = 0;

	if (count == 0)
		data->speed = 1.5;
	else
		data->speed = 1;
	count++;
	if (count == 2)
		count = 0;
}
