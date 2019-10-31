/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:53:44 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/31 20:53:13 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

float		get_side(t_data *dt, t_ray *r, t_sprite *s)
{
	float	x;
	float	y;
	float	dist;
	float	dist2;

	y = dt->pos_y + (float)s->dst * r->rdir_y;
	x = dt->pos_x + (float)s->dst * r->rdir_x;
	x = x - dt->pos_x;
	y = y - dt->pos_y;
	dist = sqrt(x * x + y * y);
	if ((dt->dir_x > 0.5 || dt->dir_x < -0.5) && (dt->dir_y < 0.5 &&
		dt->dir_y > -0.5))
		s->y_s = dt->pos_y + y - dt->pos_y;
	else
		s->y_s = dt->pos_x + x - dt->pos_x;
	dist2 = sqrt(s->y_s * s->y_s);
	return (to_degree(acos(dist2 / dist)));
}

void		draw_weapon(t_data *data)
{
	data->weapon.ptr = mlx_png_file_to_image(data->ptr,
	"textures/sprites/BackR01.png", &data->weapon.width, &data->weapon.height);
	if (data->weapon.ptr == 0)
		printf("ca marche pas\n");
}
