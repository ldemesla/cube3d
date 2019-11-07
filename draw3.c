/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:13:20 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 17:38:21 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		draw_life(t_data *data)
{
	float	x;
	float	y;
	int		size;
	int		len;

	y = data->width * 0.03;
	size = (data->width * 0.7 - data->width * 0.3) * data->life;
	while (++y < data->height * 0.13)
	{
		x = data->width * 0.3;
		len = 0;
		while (++x < (data->width * 0.7))
		{
			if (len < size)
				data->img.data[(int)x + (int)y * data->width] = 16711680;
			else
				data->img.data[(int)x + (int)y * data->width] = 20;
			len++;
		}
	}
}
