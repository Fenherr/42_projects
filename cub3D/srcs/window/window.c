/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:12:12 by hde-min           #+#    #+#             */
/*   Updated: 2022/12/26 11:16:29 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_put_image(t_data *data)
{
	/*
	test avec put image
	t_image floor;
	t_image ground;
	
	floor.height = 497;
	floor.width = 1920;
	floor.img = mlx_xpm_file_to_image(data->mlx, "images/blue.xpm", &floor.width, &floor.height);
	mlx_put_image_to_window(data->mlx, data->win, floor.img, 0, 0);
	ground.height = 497;
	ground.width = 1920;
	ground.img = mlx_xpm_file_to_image(data->mlx, "images/green.xpm", &ground.width, &ground.height);
	mlx_put_image_to_window(data->mlx, data->win, ground.img, 0, 497);*/
	/*
	test avec put pixel
	
	int	i;
	int	j;
	int	color;
	
	i = 0;
	j = 0;
	color = 0x00BFFF;
	while (j < data->screen_height)
	{
		if (j == data->screen_height / 2)
			color = 0x008000;
		while (i < data->screen_width)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, color);
			i++;
		}
		j++;
		i = 0;
	}*/
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;
	int	i;
	int	j;
	int	color;
	int	*test;
	
	image = mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	test = (int *)mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	
	i = 0;
	j = 0;
	color = 0x00BFFF;
	while (j < data->screen_height)
	{
		if (j == data->screen_height / 2)
			color = 0x008000;
		while (i < data->screen_width)
		{
			test[j * data->screen_width + i] = color;
			i++;
		}
		j++;
		i = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, image, 0, 0);
}

void	ft_free(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_array(data->map);
	exit (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_free(data);
	return (0);
}

int	ft_mouse_hook(t_data *data)
{
	ft_free(data);
	return (0);
}

void	ft_start_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->screen_width, data->screen_height, "Cube 3D");
	ft_put_image(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 1L >> 2, ft_mouse_hook, data);
	mlx_loop(data->mlx);
}
