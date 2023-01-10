/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:13:34 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/02 14:13:34 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

double	ft_wall_x(t_wall_moove *wall, t_data *data, int i)
{
	if (data->map[ft_round(data->y_p)][ft_round(wall->xtemp)] == '1')
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

double	ft_wall_y(t_wall_moove *wall, t_data *data, int i)
{
	if (data->map[ft_round(wall->ytemp)][ft_round(data->x_p)] == '1')
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
