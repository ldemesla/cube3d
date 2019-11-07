/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:24:35 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 17:38:40 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_ray(t_ray *ray, t_data *data)
{
	ray->map_x = (int)data->pos_x;
	ray->map_y = (int)data->pos_y;
	ray->camera_x = 2 * data->x / (double)data->width - 1;
	ray->rdir_x = data->dir_x + data->plane_x * ray->camera_x;
	ray->rdir_y = data->dir_y + data->plane_y * ray->camera_x;
	ray->d_dist_x = fabs(1 / ray->rdir_x);
	ray->d_dist_y = fabs(1 / ray->rdir_y);
	ray->hit = 0;
	ray->sprite = 0;
}

void	init_dist(t_ray *ray, t_data *data)
{
	if (ray->rdir_x < 0 && (ray->step_x = -1) == -1)
		ray->dist_x = (data->pos_x - ray->map_x) * ray->d_dist_x;
	else
	{
		ray->dist_x = (-data->pos_x + 1 + ray->map_x) * ray->d_dist_x;
		ray->step_x = 1;
	}
	if (ray->rdir_y < 0 && (ray->step_y = -1) == -1)
		ray->dist_y = (data->pos_y - ray->map_y) * ray->d_dist_y;
	else
	{
		ray->dist_y = (-data->pos_y + 1 + ray->map_y) * ray->d_dist_y;
		ray->step_y = 1;
	}
}

int		dda(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->d_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->dist_y += ray->d_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_x][ray->map_y] == 2)
			if (!(add_sprite(data, ray)))
				return (0);
		if (data->map[ray->map_x][ray->map_y] == 1)
			ray->hit = 1;
	}
	return (1);
}

void	get_wall_height(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - data->pos_x + (1 -
		ray->step_x) / 2) / ray->rdir_x;
	else
		ray->wall_dist = (ray->map_y - data->pos_y + (1 -
		ray->step_y) / 2) / ray->rdir_y;
	ray->wall_height = (int)((float)data->height / (float)ray->wall_dist);
	ray->lower_pix = (int)(-ray->wall_height / 2 + data->height / 2);
	if (ray->lower_pix < 0)
		ray->lower_pix = 0;
	ray->higher_pix = ray->wall_height / 2 + data->height / 2;
	if (ray->higher_pix > data->height)
		ray->higher_pix = data->height - 1;
}

int		ray_casting(t_data *data, char *line)
{
	t_ray *ray;

	if (!init(&ray, &data))
		return (0);
	draw_sky_floor(data);
	while (++data->x < data->width)
	{
		init_ray(ray, data);
		init_dist(ray, data);
		if (!(dda(ray, data)))
			return (0);
		get_wall_height(ray, data);
		draw_pix_column(ray, data);
		draw_sprites(data, ray);
	}
	draw_life(data);
	draw_map(data);
	draw_weapon(data, line);
	clear_ray(&ray);
	mlx_put_image_to_window(data->ptr, data->win, data->img.ptr, 0, 0);
	free(data->img.ptr);
	return (1);
}
