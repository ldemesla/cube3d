/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:19:36 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/26 12:11:36 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// Ajotuer collision, jsute regarder si le carre = a 0

void	move_up(t_data *data)
{
	data->pos_x += data->dir_x;
	data->pos_y += data->dir_y;
}

void	move_down(t_data *data)
{
	data->pos_x -= data->dir_x;
	data->pos_y -= data->dir_y;
}

void	rotate_right(t_data *data)
{
	double temp;

	temp = data->dir_x;
	data->dir_x = temp * cos(-0.3839724) - data->dir_y * sin(-0.3839724);
	data->dir_y = temp * sin(-0.3839724) + data->dir_y * cos(-0.3839724);
	temp = data->plane_x;
	data->plane_x = temp * cos(-0.3839724) - data->plane_y * sin(-0.3839724);
	data->plane_y = temp * sin(-0.3839724) + data->plane_y * cos(-0.3839724);
}

void	rotate_left(t_data *data)
{
	double temp;

	temp = data->dir_x;
	data->dir_x = temp * cos(0.3839724) - data->dir_y * sin(0.3839724);
	data->dir_y = temp * sin(0.3839724) + data->dir_y * cos(0.3839724);
	temp = data->plane_x;
	data->plane_x = temp * cos(0.3839724) - data->plane_y * sin(0.3839724);
	data->plane_y = temp * sin(0.3839724) + data->plane_y * cos(0.3839724);
}
