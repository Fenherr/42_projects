/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:30:04 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 13:30:04 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_double_wall1(t_data *data, t_add *add, t_texture *t)
{
	if (data->y_p > t->y)
		return (data->wall.n[add->a_north]);
	else
		return (data->wall.s[add->a_south]);
}

int	ft_double_wall2(t_data *data, t_add *add, t_texture *t)
{
	if (data->x_p < t->x)
		return (data->wall.e[add->a_east]);
	else
		return (data->wall.w[add->a_west]);
}
