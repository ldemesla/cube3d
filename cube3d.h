/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:56:47 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/25 17:20:33 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define WIDTH 1024
# define HEIGHT 1024
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			endian;
	int			size_l;
	int			width;
	int			height;
}				t_img;

typedef struct	s_data
{
	void		*ptr;
	void		*win;
	t_img		img;
	double		x;
	double		pos_x;
	double		pos_y;
	double		dir_y;
	double		dir_x;
	double		plane_x;
	double		plane_y;
	int			*map;
}				t_data;

typedef struct	s_ray
{
	int			map_x;
	int			map_y;
	double		dist_x;
	double		dist_y;
	double		d_dist_x;
	double		d_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_dist;
	int			wall_height;
	int			lower_pix;
	int			higher_pix;
	double		camera_x;
	double		rdir_x;
	double		rdir_y;
}				t_ray;
void			draw_pix_column(t_ray *ray, t_data *data);
int				ray_casting(t_data *data);
#endif
