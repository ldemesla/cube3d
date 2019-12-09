/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:53:44 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 15:33:45 by ldemesla         ###   ########.fr       */
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

void		shot(t_data *data)
{
	static int count = 0;

	if (count == 0)
		ray_casting(data, "textures/sprites/shot2.XPM");
	else if (count == 1)
		ray_casting(data, "textures/sprites/shot3.XPM");
	else if (count == 2)
		ray_casting(data, "textures/sprites/shot4.XPM");
	else
		ray_casting(data, "textures/sprites/shot1.XPM");
	count++;
	if (count == 4)
		count = 0;
}

void		set_weapon(t_data *data, char *line)
{
	data->weapon.ptr = mlx_xpm_file_to_image(data->ptr, line,
	&data->weapon.width, &data->weapon.height);
	data->weapon.data = (int*)mlx_get_data_addr(data->weapon.ptr,
	&data->weapon.bpp, &data->weapon.size_l, &data->weapon.endian);
}

void		draw_map(t_data *data)
{
	float	x;
	float	y;
	int		color;
	float	i;
	float	j;

	y = -1;
	j = 0;
	while (++y < data->width * 0.15 && (i = 0) == 0)
	{
		x = -1;
		while (++x < (data->width * 0.15))
		{
			if ((int)i == (int)data->pos_y && (int)j == (int)data->pos_x)
				color = 16711680;
			else if (data->map[(int)j][(int)i] == 0)
				color = 16448250;
			else
				color = 0;
			if (color != 0)
				data->img.data[(int)x + (int)y * data->width] = color;
			i += (float)(data->map_width / (data->width * 0.15));
		}
		j += (float)data->map_height / (data->width * 0.15);
	}
}

void		draw_weapon(t_data *data, char *line)
{
	float	x;
	float	y;
	int		color;
	float	i;
	float	j;

	y = (float)data->height * 0.5 - 1;
	if ((j = 0) == 0 && data->weapon.ptr)
		free(data->weapon.ptr);
	set_weapon(data, line);
	while (++y <= (data->height - 1))
	{
		x = (data->width * 0.4) - 1;
		i = 0;
		while (x < (data->width * 0.65 - 1))
		{
			color = data->weapon.data[(int)((int)i + (int)j *
			(data->weapon.width))];
			if (color != 42217)
				data->img.data[(int)x + (int)y * data->width] = color;
			i += (float)(data->weapon.width) / (float)((data->width) * 0.25);
			x++;
		}
		j += (float)(data->weapon.height - 1) / (data->height * 0.5);
	}
}
