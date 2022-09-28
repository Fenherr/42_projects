/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/23 16:11:59 by ngrenoux         ###   ########.fr       */
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

int main(void)
{
	void 	*mlx;
	void 	*mlx_win;
	t_images	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	ft_put_pixel(&img, 200, 200, 0xFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
}