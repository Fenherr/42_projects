/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/05 14:11:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SOL_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../lib/mlx_linux/mlx.h"

typedef struct s_image
{
	void	*img;
	char	*path;
	int		width;
	int		length;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map_name;
	char	**map;
	int		map_width;
	int		map_length;
	int		item;
	int		exit;
	int		player;
	t_image	img;
}	t_data;

void	ft_error_msg(char *str);
void	ft_error_elm(t_data *data);
void	ft_check_map(t_data *data);
void	ft_init(t_data *data, char *map_name);
void	ft_map_len(t_data *data);

#endif