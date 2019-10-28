/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:41:59 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/28 14:55:35 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		draw_pix_column(t_ray *ray, t_data *data)
{
	while (ray->higher_pix >= ray->lower_pix)
	{
		data->img.data[data->width * (ray->higher_pix - 1) +
		(int)data->x] = 200;
		ray->higher_pix--;
	}
	return (1);
}
