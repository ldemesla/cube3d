/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:41:59 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 17:13:00 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			draw_pix_column(t_ray *ray, t_data *data)
{
	double	tex_x;
	double	y;
	int		size;
	int		*texture;
	int		diff;

	diff = 0;
	if (ray->higher_pix <= ray->wall_height)
		diff = (ray->wall_height - ray->higher_pix) / 2;
	texture = get_texture(data, ray);
	size = get_size(data, ray);
	y = (double)size / (double)ray->wall_height;
	tex_x = data->pos_x + ray->wall_dist * ray->rdir_x;
	if (ray->side == 0)
		tex_x = data->pos_y + ray->wall_dist * ray->rdir_y;
	tex_x = tex_x - floor(tex_x);
	while (ray->lower_pix < ray->higher_pix)
	{
		data->img.data[(int)data->x + (ray->lower_pix * data->width)] =
		texture[(int)(tex_x * (double)size - 1)
		+ ((int)((ray->higher_pix - ray->lower_pix + diff) * y) * (size))];
		ray->lower_pix++;
	}
	return (1);
}

void		draw_sky_floor(t_data *data)
{
	int		i;

	i = 0;
	data->x = -1;
	data->to_draw = 0;
	while (i < (data->width * data->height))
	{
		if (i < (data->width * data->height / 2))
			data->img.data[i] = (data->floor.R << 16) + (data->floor.G << 8)
			+ data->floor.B;
		else
			data->img.data[i] = (data->ceiling.R << 16) +
			(data->ceiling.G << 8) + data->ceiling.B;
		i++;
	}
}

void		draw_sprites_column(t_data *dt, t_sprite *s)
{
	int		lower_pix;
	int		higher_pix;
	int		p_x;
	int		color;
	int		i;

	i = 0;
	if (s->diff < dt->to_draw->diff)
		p_x = dt->to_draw->diff * -1 + (dt->to_draw->size / 2);
	else
		p_x = dt->to_draw->diff + (dt->to_draw->size / 2);
	p_x = (float)p_x * (dt->sprite.width / dt->to_draw->size);
	lower_pix = (-dt->to_draw->size / 2 + dt->height / 2) - 1;
	higher_pix = (dt->to_draw->size / 2 + dt->height / 2);
	if (lower_pix < 0)
		lower_pix = 0;
	if (higher_pix > dt->height)
		higher_pix = dt->height - 1;
	while (++lower_pix < higher_pix)
	{
		color = dt->sprite.data[p_x + (int)(i++ * ((float)dt->sprite.height /
		(float)dt->to_draw->size)) * (dt->sprite.width)];
		if (color != 16515324)
			dt->img.data[(int)dt->x + ((lower_pix * (dt->width)))] = color;
	}
}

double		get_center(t_data *dt, t_sprite *s)
{
	double	x;
	double	y;
	double	dist;
	double	dist2;

	x = s->x - dt->pos_x;
	y = s->y - dt->pos_y;
	dist = sqrt(x * x + y * y);
	if ((dt->dir_x > 0.5 || dt->dir_x < -0.5) && (dt->dir_y < 0.5 &&
		dt->dir_y > -0.5))
		s->y_c = dt->pos_y + y - dt->pos_y;
	else
		s->y_c = dt->pos_x + x - dt->pos_x;
	dist2 = sqrt(s->y_c * s->y_c);
	s->size = dt->height / dist;
	return (to_degree(acos(dist2 / dist)));
}

void		draw_sprites(t_data *dt, t_ray *ray)
{
	t_sprite	*s;
	float		angle_s;
	float		angle_c;

	s = ray->sprite;
	while (s)
	{
		angle_c = get_center(dt, s);
		angle_s = get_side(dt, ray, s);
		if ((s->y_c > 0 && s->y_s < 0) || (s->y_c < 0 && s->y_s > 0))
			s->diff = (180 - angle_c - angle_s) * (float)(dt->width / 66);
		else
			s->diff = (angle_s - angle_c) * ((float)(dt->width) / 66);
		s->diff = fabs(s->diff);
		if (dt->to_draw && dt->to_draw->diff < (dt->to_draw->size / 2))
			draw_sprites_column(dt, s);
		dt->to_draw = s;
		s = s->next;
	}
}
