/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:56:47 by ldemesla          #+#    #+#             */
/*   Updated: 2019/10/28 16:33:36 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_gnl
{
	char		buff[BUFFER_SIZE];
	int			i;
	int			res;
}				t_gnl;

int				get_next_line(int fd, char **line);
int				str_len(char *s);
int				ft_alloc(char c, char **line);
int				re_loop(t_gnl *data, int fd);
int				init_line(char **line);
int				reset_props(t_gnl **data, int i);

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

typedef struct s_color
{
	int R;
	int G;
	int B;
	int	set;
}				t_color;

typedef struct	s_data
{
	void		*ptr;
	void		*win;
	t_img		img;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		sprite;
	double		x;
	double		pos_x;
	double		pos_y;
	double		dir_y;
	double		dir_x;
	double		plane_x;
	double		plane_y;
	int			**map;
	int			map_height;
	int			map_width;
	int			valid;
	int			width;
	int			height;
	int			save;
	t_color		floor;
	t_color		ceiling;
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
int				draw_pix_column(t_ray *ray, t_data *data);
int				ray_casting(t_data *data);
void			move_up(t_data *data);
void			move_down(t_data *data);
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);
void			reset_image(t_data *data);
int				parse_args(char **av, t_data *data);
int				get_number(char *line, int index);
int				add_line(t_data *data, char *line, int nb);
int				check_last(t_data *data);
int				ft_strlen_map(char *line);
char			*remove_space(char *line);
int				check_extension(char *line);
int				ft_compare(char *line, char *set);
char			*to_file(char *line, char c);
void			free_map(t_data *data);
void			free_data(t_data **data);
#endif
