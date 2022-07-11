/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:56:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/07 11:23:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../lib/mlx_linux/mlx.h"

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
