/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:30:48 by hde-min           #+#    #+#             */
/*   Updated: 2022/12/27 12:30:49 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

void	ft_look_right(t_data *data)
{
	if (data->view + 0.200000000000 > 12)
		data->view = 0;
	else
		data->view = data->view + 0.2;
}

void	ft_look_left(t_data *data)
{
	if (data->view - 0.200000000000 < 0)
		data->view = 12 - 0.2;
	else
		data->view = data->view - 0.2;
}

void	ft_look_right_2(t_data *data)
{
	if (data->view >= 12)
		data->view = 0;
	data->view = data->view + 3;
}

void	ft_look_left_2(t_data *data)
{
	if (data->view <= 0)
		data->view = 12;
	data->view = data->view - 3;
}
