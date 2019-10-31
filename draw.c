/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:41:59 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/30 22:46:58 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			draw_pix_column(t_ray *ray, t_data *data)
{
	double	texX;
	int		texY;
	double	y;
	int		size;
	int		*texture;
	int		diff;

	diff = 0;
	if (ray->higher_pix < ray->wall_height)
		diff = (ray->wall_height - ray->higher_pix) / 2;
	texture = get_texture(data, ray);
	size = get_size(data, ray);
	y = (double)size / (double)ray->wall_height;
	texX = data->pos_x + ray->wall_dist * ray->rdir_x;
	if (ray->side == 0)
		texX = data->pos_y + ray->wall_dist * ray->rdir_y;
	texX = texX - floor(texX);
	while (ray->lower_pix < ray->higher_pix)
	{
		data->img.data[(int)data->x + (ray->lower_pix * data->width)] =
		texture[(int)(texX * (double)size - 1)
		+ ((int)((ray->higher_pix - ray->lower_pix + diff) * y) * size)];
		ray->lower_pix++;
	}
	return (1);
}

void		draw_sky_floor(t_data *data)
{
	int		i;

	i = 0;
	data->x = 0;
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

void		draw_sprites_column(t_data *data, t_ray *ray, t_sprite *s)
{
	int lower_pix;
	int	higher_pix;

	if (s->diff < (s->size / 2) && s->diff > -(s->size / 2))
	{
		lower_pix= -s->size / 2 + data->height / 2;
		higher_pix = s->size / 2 + data->height / 2;
		while (lower_pix < higher_pix)
		{
			data->img.data[(int)data->x + (lower_pix * data->width)] = 200;
			lower_pix++;
		}
	}
}

double		get_center(t_data *dt, t_sprite *s, t_ray *ray)
{
	double	x;
	double	y;
	double	x2;
	double	dist;
	double	dist2;

	x = s->x - dt->pos_x;
	y = s->y - dt->pos_y;
	dist = sqrt(x*x + y*y);
	s->y_c = dt->pos_y + y -dt->pos_y;
	x2 = sqrt((dt->pos_x + x -dt->pos_x) * (dt->pos_x + x -dt->pos_x));
	dist2 = sqrt(x2 * x2);
	s->size = dt->height / dist;
	return (to_degree(acos(dist2 / dist)));
}

void		draw_sprites(t_data *data, t_ray *ray)
{
	t_sprite	*s;
	float		angle_s;
	float		angle_c;
	float		diff;

	s = ray->sprite;
	while (s)
	{
		angle_c = get_center(data, s, ray);
		angle_s = get_side(data, ray, s);
		if ((s->y_c >= 0 && s->y_s <= 0) || (s->y_c <= 0 && s->y_s >= 0))
		{
			printf("differents!!\n");
			s->diff = (180 - angle_c - angle_s) * (float)(data->width / 66);
		}
		else
			s->diff = (angle_s - angle_c) * ((float)(data->width) / 66);
		printf("%f, %f\n", s->y_c, s->y_s);
		draw_sprites_column(data, ray, s);
		s = s->next;
	}
}
