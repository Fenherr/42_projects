/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/04 14:57:56 by ngrenoux         ###   ########.fr       */
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
/*                            STRUCTURES                        */
/*==============================================================*/
typedef struct s_image
{
	void		*img;
	int			height;
	int			width;
}	t_image;

typedef struct s_wall
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	t_image		img;
}	t_wall;

typedef struct s_colors
{
	char		*floor;
	char		*ceiling;
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
	int			nb_player;
	t_wall		wall;
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
/*--------------------------check_map.c------------------------*/
void	ft_check_map(t_data *data);

/*-----------------------check_map_utils.c---------------------*/
int		ft_check_diagonal(t_data *data, int i, int j);
int		ft_if_high_len(t_data *data, int i, int j);

#endif
