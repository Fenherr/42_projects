/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/28 16:00:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putchar('X');
	return (0);
}

void	ft_put_pixel(t_images *data, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < 50)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x--;
		y++;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x++;
		i++;
	}
	i = 0;
	while (i < 50)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x++;
		y--;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x--;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		y++;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x++;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		y--;
		i++;
	}
	i = 0;
	while (i < 50)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x--;
		y++;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		y++;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x--;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		y--;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		y++;
		i++;
	}
	i = 0;
	while (i < 50)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x++;
		y--;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x++;
		i++;
	}
	i = 0;
	while (i < 50)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
		x--;
		y++;
		i++;
	}
}

int	ft_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	return (0);
}

int main(void)
{
	t_window	data;
	t_images	img;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "So_long");
	img.img = mlx_new_image(data.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	ft_put_pixel(&img, 200, 200, 0xFFFFFF);
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_hook(data.win, 17, 1L<<17, ft_close, (void *)0);
	mlx_hook(data.win, 2, 1L<<0, ft_close, &data);

	mlx_loop(data.mlx);
	free(data.mlx);
}