/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/05 14:35:46 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_test(t_data *data)
{
	data->img.path = "./resources/tiles/floor.xpm";
	data->img.img = mlx_xpm_file_to_image(data->mlx, data->img.path,
		&data->img.width, &data->img.length);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	ft_esc_close(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac != 2)
		return (0);
	ft_init(&data, av[1]);
	ft_check_map(&data);
	ft_map_len(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.map_length * 32, data.map_width * 32, "So_long");
	mlx_loop_hook(data.mlx, &ft_test, &data);
	mlx_hook(data.win, 2, 1L<<0, &ft_esc_close, &data);
	mlx_loop(data.mlx);
}
