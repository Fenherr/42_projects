/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:05:38 by hde-min           #+#    #+#             */
/*   Updated: 2022/12/27 11:05:39 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_init_view(char facing)
{
	if (facing == 'N')
		return (0);
	else if (facing == 'S')
		return (6);
	else if (facing == 'E')
		return (3);
	else if (facing == 'W')
		return (9);
	return (0);
}

void	ft_init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'S'
				|| data->map[y][x] == 'W')
			{
				data->x_p = (float)x + 0.5;
				data->y_p = (float)y + 0.5;
				data->view = ft_init_view(data->map[y][x]);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
