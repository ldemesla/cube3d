/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:56:54 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/28 16:29:46 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_map(t_data *data)
{
	int i;

	i = 0;
	printf("%d\n", data->map_height);
	while (i < data->map_height)
	{
		free(data->map[i]);
		printf("%d\n", i);
		i++;
	}
	free(data->map);
}

void	free_data(t_data **data)
{
	free(data[0]->ptr);
	free(data[0]->win);
	free(data[0]->north.ptr);
	free(data[0]->south.ptr);
	free(data[0]->east.ptr);
	free(data[0]->west.ptr);
	free(data[0]);
}
