/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:47:03 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 14:12:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_fill_image(t_data *data, t_texture *texture)
{
	long int	j;
	long int	i;

	j = 0;
	if (texture->height >= WIN_HEIGHT)
		texture->height = WIN_HEIGHT;
	while (j <= texture->height)
	{
		i = ((((j + ((WIN_HEIGHT / 2) - (texture->height / 2))))
					* WIN_WIDTH) + (data->square));
		if (i >= WIN_HEIGHT * WIN_WIDTH)
			i = (WIN_HEIGHT * WIN_WIDTH) - 2;
		if (i < (WIN_HEIGHT * WIN_WIDTH) && i > 0)
			data->screen[i] = ft_texture(data, j, texture);
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
	float		distance;
	float		height;
	float		diffangle;
	t_texture	texture;

	distance = ft_distance_to_player(data, x, y);
	diffangle = ft_clock(angle) - ft_clock(data->view);
	if (diffangle > 300)
		diffangle -= 360;
	diffangle = ft_radiant(diffangle);
	distance = distance * cos(diffangle);
	height = (500 / distance);
	texture.height = ft_better_round(height);
	texture.x = x;
	texture.y = y;
	texture.angle = angle;
	ft_fill_image(data, &texture);
}

void	ft_raycast(t_data *data, double angle)
{
	double	i;
	double	j;
	double	x;
	double	y;

	i = ft_lmove_x(angle) / 50;
	j = ft_lmove_y(angle) / 50;
	x = data->x_p;
	y = data->y_p;
	while (data->map[ft_round(y)][ft_round(x)] != '1')
	{
		x = x + i;
		y = y + j;
	}
	ft_put_wall(data, x, y, angle);
}
