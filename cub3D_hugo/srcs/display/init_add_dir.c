/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:11:44 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 13:14:02 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

long int	ft_pixel_n(t_texture *t, int j, t_data *data)
{
	long int	tmp;
	double		onheight;
	double		i;

	i = t->x;
	onheight = (data->wall.north.height - 1.0) / t->height;
	tmp = i;
	i -= tmp;
	tmp = j * onheight;
	tmp = (tmp * data->wall.north.height);
	tmp = tmp + (i * data->wall.north.width);
	return (tmp);
}

long int	ft_pixel_s(t_texture *t, int j, t_data *data)
{
	long int	tmp;
	double		onheight;
	double		i;

	i = t->x;
	onheight = (data->wall.south.height - 1.0) / t->height;
	tmp = i;
	i -= tmp;
	tmp = j * onheight;
	tmp = (tmp * data->wall.south.height);
	tmp = tmp + (i * data->wall.south.width);
	return (tmp);
}

long int	ft_pixel_e(t_texture *t, int j, t_data *data)
{
	long int	tmp;
	double		onheight;
	double		i;

	i = t->y;
	onheight = (data->wall.east.height - 1.0) / t->height;
	tmp = i;
	i -= tmp;
	tmp = j * onheight;
	tmp = (tmp * data->wall.east.height);
	tmp = tmp + (i * data->wall.east.width);
	return (tmp);
}

long int	ft_pixel_w(t_texture *t, int j, t_data *data)
{
	long int	tmp;
	double		onheight;
	double		i;

	i = t->y;
	onheight = (data->wall.west.height - 1.0) / t->height;
	tmp = i;
	i -= tmp;
	tmp = j * onheight;
	tmp = (tmp * data->wall.west.height);
	tmp = tmp + (i * data->wall.west.width);
	return (tmp);
}
