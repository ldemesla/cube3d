/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:48:48 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/25 17:23:34 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_data(t_data *data)
{
	if (!(data->ptr = mlx_init()))
		return (0);
	if (!(data->win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "Cube 3d")))
		return (0);
	data->pos_x = 3;
	data->pos_y = 3;
	data->dir_x = -1;
	data->dir_y = 1;
	data->plane_x = 0.33;
	data->plane_y = 0.33;
	return (1);
}

int	main(void)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		return (0);
	init_data(data);
	if (!ray_casting(data))
		return (0);
	mlx_loop(data->ptr);
	return (0);
}
