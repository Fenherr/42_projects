/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/30 15:27:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_nothing(void)
{
	return (0);
}

int	ft_esc_close(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 600, 600, "Test");

	data.img.path = "../resources/tiles/floor.xpm";
	data.img.img = mlx_xpm_file_to_image(data.mlx, data.img.path, &data.img.width, &data.img.height);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	
	mlx_loop_hook(data.mlx, &ft_nothing, 0);
	mlx_hook(data.win, 2, 1L<<0, &ft_esc_close, &data);
	mlx_loop(data.mlx);
}