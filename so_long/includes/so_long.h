/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/03 13:28:45 by ngrenoux         ###   ########.fr       */
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
	int		height;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		item;
	int		exit;
	int		player;
	t_image	img;
}	t_data;

void	ft_init(t_data *data);
void	test(void);

#endif