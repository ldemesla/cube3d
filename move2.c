/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:51:41 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 14:24:34 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_right(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->plane_x)]
		[(int)(data->pos_y - data->plane_y)] == 0)
	{
		data->pos_x += (data->plane_x * 0.1);
		data->pos_y += (data->plane_y * 0.1);
	}
}

void	move_left(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->plane_x)]
		[(int)(data->pos_y - data->plane_y)] == 0)
	{
		data->pos_x -= (data->plane_x * 0.1);
		data->pos_y -= (data->plane_y * 0.1);
	}
}
