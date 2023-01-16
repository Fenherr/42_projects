/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:51:27 by hde-min           #+#    #+#             */
/*   Updated: 2022/12/27 10:51:27 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	key_hook_2(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_Up)
		ft_moove(data, 8);
	else if (keycode == XK_a)
		ft_moove(data, 4);
	else if (keycode == XK_s || keycode == XK_Down)
		ft_moove(data, 2);
	else if (keycode == XK_d)
		ft_moove(data, 6);
	else if (keycode == XK_Right)
		ft_look_right(data);
	else if (keycode == XK_Left)
		ft_look_left(data);
	else if (keycode == XK_q)
		ft_look_left_2(data);
	else if (keycode == XK_e)
		ft_look_right_2(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_free(data);
	if (data->cpt_moove > 0)
		data->cpt_moove = 0;
	else
	{
		data->cpt_moove++;
		return (-1);
	}
	key_hook_2(keycode, data);
	ft_to_see(data);
	ft_minimap(data);
	return (0);
}

int	ft_mouse_hook(t_data *data)
{
	ft_free(data);
	return (0);
}
