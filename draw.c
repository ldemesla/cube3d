/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:41:59 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/25 16:05:31 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_pix_column(t_ray *ray, t_data *data)
{
	while (ray->lower_pix < ray->higher_pix)
	{
		mlx_pixel_put(data->ptr, data->win, data->x, ray->lower_pix, 200);
		ray->lower_pix++;
	}
}
