/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:10:07 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/16 10:12:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

long int	ft_pixel(double i, int j, int height)
{
	long int	tmp;
	double		onheight;

	onheight = 31.0 / height;
	tmp = i;
	i -= tmp;
	tmp = j * onheight;
	tmp = (tmp * 32);
	tmp = tmp + (i * 32);
	return (tmp);
}

int	ft_dir(double angle)
{
	if (angle < 3)
		return (9);
	else if (angle >= 3 && angle < 6)
		return (3);
	else if (angle >= 6 && angle < 9)
		return (1);
	else if (angle >= 9)
		return (7);
	return (9);
}

int	ft_special_wall(t_data *data, long int tmp, long int tmp2, t_texture *t)
{
	int	color;
	int	dir;
	int	xtemp;
	double	xt;

	color = 0;
	xtemp = t->x;
	xt = t->x;
	xt -= xtemp;
	dir = ft_dir(t->angle);
	if (dir == 9)
	{
		if (xt > 0.01)
			return ((data->wall.n[tmp2]));
		else
			return ((data->wall.e[tmp]));
	}
	else if (dir == 3)
	{
		if (xt > 0.01)
			return ((data->wall.s[tmp2]));
		else
			return ((data->wall.e[tmp]));
	}
	else if (dir == 1)
	{
		if (xt < 0.99)
			return ((data->wall.s[tmp2]));
		else
			return ((data->wall.w[tmp]));
	}
	else if (dir == 7)
	{
		if (xt > 0.99)
			return ((data->wall.w[tmp]));
		else
			return ((data->wall.n[tmp2]));
	}
	return (color);
}

int	ft_texture(t_data *data, int j, t_texture *t)
{
	int			color;
	long int	tmp;
	long int	tmp2;
	double		onheight;

	onheight = 31.0 / t->height;
	tmp = ft_pixel(t->y, j, t->height);
	tmp2 = ft_pixel(t->x, j, t->height);
	if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '1')
		return (data->wall.n[tmp2]);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '2')
		return (data->wall.s[tmp2]);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '3')
		return (data->wall.w[tmp]);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '4')
		return (data->wall.e[tmp]);
	else
	{
		color = ft_special_wall(data, tmp, tmp2, t);
		return (color);
	}
}
