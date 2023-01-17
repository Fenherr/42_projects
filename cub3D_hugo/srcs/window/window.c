/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:12:12 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 14:14:45 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_mouse_moove(int x, int y, t_data *data)
{
	(void)y;
	data->x_moose = x;
	return (1);
}

int	ft_mouse_look(t_data *data)
{
	if (data->moose > 5000)
	{
		data->moose = 0;
		if (data->x_moose > (WIN_WIDTH / 2) + ((WIN_WIDTH / 2) / 4))
			ft_look_right(data);
		else if (data->x_moose < (WIN_WIDTH / 2) - ((WIN_WIDTH / 2) / 4))
			ft_look_left(data);
		ft_to_see(data);
		ft_minimap(data);
	}
	else
		data->moose++;
	return (0);
}

void	ft_start_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH,
			WIN_HEIGHT, "Cube 3D");
	data->floor_and_celling = ft_create_image_2(data);
	ft_put_pixel(data, data->floor_and_celling);
	data->screen = ft_create_image(data);
	data->minimap = ft_create_minimap(data);
	ft_set_texture(data);
	ft_to_see(data);
//	ft_minimap(data);
//	mlx_hook(data->win, 6, 1L << 6, ft_mouse_moove, data);
//	mlx_loop_hook(data->mlx, ft_mouse_look, data);
//	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_hook, data);
	mlx_loop(data->mlx);
}
