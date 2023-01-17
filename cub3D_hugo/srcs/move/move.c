/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:30:42 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 14:12:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_move_2(t_data *data, int i, t_wall_move *wall)
{
	if (i == 2)
	{
		wall->xtemp = data->x_p - wall->x;
		wall->ytemp = data->y_p - wall->y;
	}
	else if (i == 4)
	{
		wall->xtemp = data->x_p + wall->y;
		wall->ytemp = data->y_p - wall->x;
	}
	data->x_p = ft_wall_x(wall, data, i);
	data->y_p = ft_wall_y(wall, data, i);
}

void	ft_move(t_data *data, int i)
{
	t_wall_move	wall;

	wall.x = ft_lmove_x(data->view);
	wall.y = ft_lmove_y(data->view);
	if (i == 8)
	{
		wall.xtemp = data->x_p + wall.x;
		wall.ytemp = data->y_p + wall.y;
	}
	else if (i == 6)
	{
		wall.xtemp = data->x_p - wall.y;
		wall.ytemp = data->y_p + wall.x;
	}
	ft_move_2(data, i, &wall);
}
