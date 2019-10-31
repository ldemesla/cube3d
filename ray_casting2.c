/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:12:49 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/30 12:15:13 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		add_sprite(t_data *data, t_ray *ray)
{
	t_sprite	*temp;
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
			return (0);
	new->y = ray->map_y + 0.5;
	new->x = ray->map_x + 0.5;
	if (ray->side == 0)
		new->dst = (ray->map_x - data->pos_x + (1 - ray->step_x) / 2) /
		ray->rdir_x;
	else
		new->dst = (ray->map_y - data->pos_y + (1 - ray->step_y) / 2) /
		ray->rdir_y;
	if (ray->sprite == 0)
	{
		ray->sprite = new;
		new->next = 0;
	}
	else
	{
		temp = ray->sprite->next;
		ray->sprite = new;
		new->next = temp;
	}
	return (1);
}
