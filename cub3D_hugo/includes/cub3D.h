/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/10 14:37:36 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"

/*==============================================================*/
/*                             MACROS                           */
/*==============================================================*/
# define WIN_WIDTH 1920
# define WIN_HEIGHT 994
# define FOV 1

/*==============================================================*/
/*                            STRUCTURES                        */
/*==============================================================*/
typedef struct s_image
{
	void		*img;
	int			height;
	int			width;
}	t_image;

typedef struct s_wall_moove
{
	double	x;
	double	y;
	double	xtemp;
	double	ytemp;
}	t_wall_moove;

typedef struct s_minimap
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_minimap;

typedef struct s_wall
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	t_image		north;
	t_image		south;
	t_image		west;
	t_image		east;
}	t_wall;

typedef struct s_colors
{
	char		*floor_data;
	char		*ceiling_data;
	int			floor;
	int			ceiling;
}	t_colors;

typedef struct s_error
{
	int			dup_north;
	int			dup_south;
	int			dup_west;
	int			dup_east;
	int			dup_floor;
	int			dup_ceiling;
	int			nb_player;
}	t_error;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*map_path;
	char		**map;
	int			map_height;
	double		x_p;
	double		y_p;
	double		view;
	int			*minimap;
	int			*screen;
	int			square;
	t_wall		wall;
	t_image		image[6];
	t_colors	colors;
	t_error		error;
}	t_data;

/*==============================================================*/
/*                            FONCTIONS                         */
/*==============================================================*/

/*------------------------------init.c--------------------------*/
void	ft_init(t_data *data, char *map_name);

/*------------------------------error.c-------------------------*/
void	ft_error_msg(char *str, char *free_str, char **free_arr);

/*------------------------------free.c--------------------------*/
void	ft_free_all(t_data *data);
void	ft_free_array(char **arr);

/*-----------------------------utils.c--------------------------*/
void	ft_check_data(t_data *data);
void	ft_check_caracters_utils(t_data *data, char *line);

/*----------------------------parsing.c-------------------------*/
void	ft_parsing(t_data *data);

/*-------------------------parsing_utils.c----------------------*/
void	ft_parse_data(t_data *data);
void	ft_check_caracters_map(t_data *data);
void	ft_check_texture_data(t_data *data);

/*----------------------------window.c-------------------------*/
void	ft_start_window(t_data *data);

/*----------------------------put_image.c-------------------------*/
void	ft_put_pixel(t_data *data, int *colorized);

/*----------------------------free_window.c-------------------------*/
void	ft_free(t_data *data);

/*----------------------------input.c-------------------------*/
int		ft_mouse_hook(t_data *data);
int		key_hook(int keycode, t_data *data);

/*----------------------------init_player.c-------------------------*/
void	ft_init_player(t_data *data);

/*----------------------------moove.c-------------------------*/
void	ft_moove(t_data *data, int i);

/*----------------------------look.c-------------------------*/
void	ft_look_right(t_data *data);
void	ft_look_left(t_data *data);
void	ft_look_right_2(t_data *data);
void	ft_look_left_2(t_data *data);

/*----------------------------math.c-------------------------*/
int		ft_round(double to_round);
double	ft_clock(double angle);
double	ft_radiant(double angle);

/*----------------------------math_2.c-------------------------*/
int		ft_better_round(double to_round);
double	ft_lmoove_y(double x);
double	ft_lmoove_x(double angle);

/*----------------------------display.c-------------------------*/
void	ft_to_see(t_data *data);

/*----------------------------raycast.c-------------------------*/
void	ft_raycast(t_data *data, double angle);

/*----------------------------start_image.c-------------------------*/
int		*ft_create_image(t_data *data);
int		*ft_create_minimap(t_data *data);

/*----------------------------wall.c-------------------------*/
double	ft_wall_x(t_wall_moove *wall, t_data *data, int i);
double	ft_wall_y(t_wall_moove *wall, t_data *data, int i);

/*--------------------------check_map.c------------------------*/
void	ft_check_map(t_data *data);

/*-----------------------check_map_utils.c---------------------*/
int		ft_check_diagonal(t_data *data, int i, int j);
int		ft_if_high_len(t_data *data, int i, int j);

/*----------------------------window.c-------------------------*/
void	ft_start_window(t_data *data);

/*----------------------------minimap.c-------------------------*/
void	ft_minimap(t_data *data);

/*------------------- ---------colors.c-------------------------*/
void	ft_colors(t_data *data);

#endif
