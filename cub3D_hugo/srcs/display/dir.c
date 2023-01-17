/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:16:57 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 13:16:58 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_dir(t_texture *t, t_data *data)
{
	double	x;
	double	y;

	x = t->x;
	y = t->y ;
	if (data->dup_map[ft_round(y - 1.0)][ft_round(x)] == '0'
		&& data->dup_map[ft_round(y)][ft_round(x - 1.0)] == '0')
		return (3);
	else if (data->dup_map[ft_round(y - 1.0)][ft_round(x)] == '0'
		&& data->dup_map[ft_round(y)][ft_round(x + 1.0)] == '0')
		return (1);
	else if (data->dup_map[ft_round(y + 1.0)][ft_round(x)] == '0'
		&& data->dup_map[ft_round(y)][ft_round(x - 1.0)] == '0')
		return (9);
	else if (data->dup_map[ft_round(y + 1.0)][ft_round(x)] == '0'
		&& data->dup_map[ft_round(y)][ft_round(x + 1.0)] == '0')
		return (7);
	return (9);
}

int	ft_dir_2(double angle)
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

int	ft_dir_y(t_texture *t, t_data *data)
{
	if (data->y_p > t->y)
	{
		if (data->map[ft_round(t->y)][ft_round(t->x - 1.0)] == '1')
			return (7);
		else if (data->map[ft_round(t->y)][ft_round(t->x + 1.0)] == '1')
			return (9);
	}
	else
	{
		if (data->map[ft_round(t->y)][ft_round(t->x - 1.0)] == '1')
			return (1);
		else if (data->map[ft_round(t->y)][ft_round(t->x + 1.0)] == '1')
			return (3);
	}
	return (0);
}

int	ft_dir_3(t_texture *t, t_data *data)
{
	int	dir;

	dir = 0;
	if (data->x_p > t->x)
	{
		if (data->map[ft_round(t->y - 1.0)][ft_round(t->x)] == '1')
			return (7);
		else if (data->map[ft_round(t->y + 1.0)][ft_round(t->x)] == '1')
			return (1);
	}
	else
	{
		if (data->map[ft_round(t->y - 1.0)][ft_round(t->x)] == '1')
			return (9);
		else if (data->map[ft_round(t->y + 1.0)][ft_round(t->x)] == '1')
			return (3);
	}
	dir = ft_dir_y(t, data);
	return (dir);
}
