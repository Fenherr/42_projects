/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:47:03 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/02 09:47:05 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_fill_image(t_data *data, int height)
{
	long int	j;
	long int	i;

	j = 0;
	while (j < height)
	{
		i = (((j + ((WIN_HEIGHT / 2)
							- (height / 2))) * WIN_WIDTH) + (data->square));
		if (i < (WIN_HEIGHT * WIN_WIDTH) && i > 0)
			data->screen[i] = 0xFFFF00;
		j++;
	}
	data->square++;
}

double	ft_distance_to_player(t_data *data, double x, double y)
{
	double	distance;

	distance = sqrt(pow((data->x_p - x), 2) + pow((data->y_p - y), 2));
	return (distance);
}

void	ft_put_wall(t_data *data, double x, double y, double angle)
{
	float	distance;
	float	height;
	float	diffangle;

	distance = ft_distance_to_player(data, x, y);
	diffangle = ft_clock(angle) - ft_clock(data->view);
	if (diffangle > 300)
		diffangle -= 360;
	diffangle = ft_radiant(diffangle);
	distance = distance * cos(diffangle);
	height = (600 / distance);
	ft_fill_image(data, ft_better_round(height));
}

void	ft_raycast(t_data *data, double angle)
{
	double	i;
	double	j;
	double	x;
	double	y;

	i = ft_lmoove_x(angle) / 10;
	j = ft_lmoove_y(angle) / 10;
	x = data->x_p;
	y = data->y_p;
	while (data->map[ft_round(y)][ft_round(x)] != '1')
	{
		x = x + i;
		y = y + j;
	}
	ft_put_wall(data, x, y, angle);
}
