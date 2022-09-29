/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/29 15:26:25 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SOL_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../lib/mlx_linux/mlx.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_images
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_images;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct	s_maps
{
	int	x;
	int	y;
	int	wall;
	int	begin;
	int	exit;
	int	collectible;
	t_player	*player;
}	t_maps;

#endif