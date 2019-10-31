/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:53:44 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/30 22:47:34 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

float		get_side(t_data *dt, t_ray *ray, t_sprite *s)
{
	float	x;
	float	y;
	float	dist;
	float	dist2;
	float	x2;

	y = dt->pos_y + (float)s->dst * ray->rdir_y;
	x = dt->pos_x + (float)s->dst * ray->rdir_x;
	x = x - dt->pos_x;
	y = y - dt->pos_y;
	dist = sqrt(x * x + y * y);
	s->y_s = dt->pos_y + y -dt->pos_y;
	x2 = sqrt((dt->pos_x + x -dt->pos_x) * (dt->pos_x + x -dt->pos_x));
	dist2 = sqrt(x2 * x2);
	return (to_degree(acos(dist2 / dist)));
}
