/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:30:42 by hde-min           #+#    #+#             */
/*   Updated: 2022/12/27 12:30:43 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

void	ft_moove_2(t_data *data, int i, t_wall_moove *wall)
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

void	ft_moove(t_data *data, int i)
{
	t_wall_moove	wall;

	data->moove = 0;
	wall.x = ft_lmoove_x(data->view);
	wall.y = ft_lmoove_y(data->view);
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
	ft_moove_2(data, i, &wall);
}
