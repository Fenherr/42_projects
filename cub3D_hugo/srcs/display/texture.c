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

int	ft_texture_2(t_data *data, t_texture *t, t_add *add)
{
	int	color;

	color = 0;
	if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '8')
		color = ft_double_wall1(data, add, t);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '9')
		color = ft_double_wall2(data, add, t);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '5')
		color = ft_special_wall(data, add, t);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '7')
		color = ft_4_wall(data, add, t);
	else
		color = ft_3_wall(data, add, t);
	return (color);
}

int	ft_texture(t_data *data, int j, t_texture *t)
{
	t_add		add;
	int			color;

	add.a_west = ft_pixel_w(t, j, data);
	add.a_north = ft_pixel_n(t, j, data);
	add.a_east = ft_pixel_e(t, j, data);
	add.a_south = ft_pixel_s(t, j, data);
	if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '2')
		return (data->wall.s[add.a_south]);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '3')
		return (data->wall.w[add.a_west]);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '4')
		return (data->wall.e[add.a_east]);
	else if (data->dup_map[ft_round(t->y)][ft_round(t->x)] == '1')
		return (data->wall.n[add.a_north]);
	else
		color = ft_texture_2(data, t, &add);
	return (color);
}
