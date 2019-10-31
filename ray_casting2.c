/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:12:49 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/31 19:54:47 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		add_sprite(t_data *dt, t_ray *r)
{
	t_sprite	*temp;
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (0);
	new->y = r->map_y + 0.5;
	new->x = r->map_x + 0.5;
	if (r->side == 0)
		new->dst = (r->map_x - dt->pos_x + (1 - r->step_x) / 2) / r->rdir_x;
	else
		new->dst = (r->map_y - dt->pos_y + (1 - r->step_y) / 2) / r->rdir_y;
	if (r->sprite == 0)
	{
		r->sprite = new;
		new->next = 0;
	}
	else
	{
		temp = r->sprite->next;
		r->sprite = new;
		new->next = temp;
	}
	return (1);
}
