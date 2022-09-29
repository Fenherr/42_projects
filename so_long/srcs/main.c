/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/29 16:24:26 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	return (0);
}

int	nothing(void)
{
	return (0);
}

int	ft_esc_close(int keysym, t_window *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int main(void)
{
	t_window	data;
	t_images	img;

	img.path = "floor.xpm";

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "So_long");
	
	img.img = mlx_xpm_file_to_image(data.mlx, img.path, &img.width, &img.height);
	mlx_loop_hook(data.mlx, &nothing, &data);
	mlx_hook(data.win, 2, 1L<<0, &ft_esc_close, &data);
	mlx_hook(data.win, 17, 1L<<17, &ft_close, (void *)0);

	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}