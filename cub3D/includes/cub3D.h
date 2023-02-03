/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/03 16:25:29 by ngrenoux         ###   ########.fr       */
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
/*                              MACROS                          */
/*==============================================================*/
# define WIN_HEIGHT 800
# define WIN_WIDTH 1600

/*==============================================================*/
/*                            STRUCTURES                        */
/*==============================================================*/

typedef struct s_wall
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
}	t_wall;

typedef struct s_colors
{
	char		*floor_data;
	char		*ceiling_data;
	int			floor;
	int			ceiling;
}	t_colors;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*map_path;
	char		**map;
	char		**dup_map;
	int			map_height;
	int			nb_player;
	t_wall		wall;
	t_colors	colors;
}	t_data;

/*==============================================================*/
/*                            FONCTIONS                         */
/*==============================================================*/

void	ft_error_msg(char *str, char *free_str, char **free_arr);
void	ft_error_and_free(char *str, t_data *data);
int		ft_is_player(char c);
void	ft_parsing(t_data *data);
void	ft_init(t_data *data, char *map_name);
void	ft_free_all(t_data *data);
void	ft_free_array(char **arr);
char	*ft_clean_dup(char *str);
void	ft_check_data(t_data *data, char *line, int fd);
char	**ft_realloc_tab_char(char **tab, char *str);
int		ft_map_begenning(char *line);

#endif
