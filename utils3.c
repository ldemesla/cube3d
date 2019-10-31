/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:27:48 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/31 20:30:03 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	clear_ray(t_ray **ray)
{
	t_sprite *temp;
	t_sprite *temp2;

	temp = ray[0]->sprite;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp);
	}
	free(*ray);
}
