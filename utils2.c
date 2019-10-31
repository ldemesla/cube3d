/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:33:18 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/30 12:04:12 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		*get_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0 && ray->rdir_x < 0)
		return (data->south.data);
	else if (ray->side == 0 && ray->rdir_x > 0)
		return (data->north.data);
	else if (ray->side == 1 && ray->rdir_y > 0)
		return (data->west.data);
	else
		return (data->east.data);
}

int		get_size(t_data *data, t_ray *ray)
{
	if (ray->side == 0 && ray->rdir_x < 0)
		return (data->south.height);
	else if (ray->side == 0 && ray->rdir_x > 0)
		return (data->north.height);
	else if (ray->side == 1 && ray->rdir_y > 0)
		return (data->west.height);
	else
		return (data->east.height);
}

float	to_radian(float degree)
{
	float   rad;
	rad = degree * (M_PI/(float)180);
	return (rad);
}

float	to_degree(float rad)
{
	float   degree;
	degree = rad / (M_PI/(float)180);
	return (degree);
}
