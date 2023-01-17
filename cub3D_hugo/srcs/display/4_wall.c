/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_wall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:35:47 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 13:35:47 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_4_wall_2(t_data *data, t_add *add, int dir, double xt)
{
	if (dir == 3)
	{
		if (xt > 0.01)
			return ((data->wall.s[add->a_south]));
		else
			return ((data->wall.e[add->a_east]));
	}
	else if (dir == 1)
	{
		if (xt < 0.99)
			return ((data->wall.s[add->a_south]));
		else
			return ((data->wall.w[add->a_west]));
	}
	else if (dir == 7)
	{
		if (xt > 0.99)
			return ((data->wall.w[add->a_west]));
		else
			return ((data->wall.n[add->a_north]));
	}
	return (0);
}

int	ft_4_wall(t_data *data, t_add *add, t_texture *t)
{
	int		color;
	int		dir;
	int		xtemp;
	double	xt;

	color = 0;
	xtemp = t->x;
	xt = t->x;
	xt -= xtemp;
	dir = ft_dir_2(t->angle);
	if (dir == 9)
	{
		if (xt > 0.01)
			return ((data->wall.n[add->a_north]));
		else
			return ((data->wall.e[add->a_east]));
	}
	else
		color = ft_4_wall_2(data, add, dir, xt);
	return (color);
}
