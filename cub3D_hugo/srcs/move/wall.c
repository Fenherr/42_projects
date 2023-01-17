/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:13:34 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/16 17:06:39 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_better_wall_x(t_data *data, t_wall_move *wall)
{
	int	wallround;

	if (wall->xtemp > data->x_p)
		wallround = (int)(wall->xtemp + 0.3);
	else
		wallround = (int)(wall->xtemp - 0.3);
	return (wallround);
}

int	ft_better_wall_y(t_data *data, t_wall_move *wall)
{
	int	wallround;

	if (wall->ytemp > data->y_p)
		wallround = (int)(wall->ytemp + 0.3);
	else
		wallround = (int)(wall->ytemp - 0.3);
	return (wallround);
}

double	ft_wall_x(t_wall_move *wall, t_data *data, int i)
{
	if (data->map[ft_round(data->y_p - 0.3)]
		[ft_better_wall_x(data, wall)] == '1'
		|| data->map[ft_round(data->y_p + 0.3)]
		[ft_better_wall_x(data, wall)] == '1')
	{
		if (i == 8)
			wall->xtemp = wall->xtemp - wall->x;
		else if (i == 2)
			wall->xtemp = wall->xtemp + wall->x;
		else if (i == 6)
			wall->xtemp = wall->xtemp + wall->y;
		else if (i == 4)
			wall->xtemp = wall->xtemp - wall->y;
		return (wall->xtemp);
	}
	return (wall->xtemp);
}

double	ft_wall_y(t_wall_move *wall, t_data *data, int i)
{
	if (data->map[ft_better_wall_y(data, wall)]
		[ft_round(data->x_p - 0.3)] == '1'
		|| data->map[ft_better_wall_y(data, wall)]
		[ft_round(data->x_p + 0.3)] == '1')
	{
		if (i == 8)
			wall->ytemp = wall->ytemp - wall->y;
		else if (i == 2)
			wall->ytemp = wall->ytemp + wall->y;
		else if (i == 6)
			wall->ytemp = wall->ytemp - wall->x;
		else if (i == 4)
			wall->ytemp = wall->ytemp + wall->x;
		return (wall->ytemp);
	}
	return (wall->ytemp);
}
