/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:49:03 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/20 10:09:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_up_move(t_data *d)
{
	if (d->map[d->player.y - 1][d->player.x] == 'C')
	{
		d->map[d->player.y - 1][d->player.x] = '0';
		d->nb_item--;
	}
	if (d->map[d->player.y - 1][d->player.x] != '1'
		&& d->map[d->player.y - 1][d->player.x] != 'E' && d->nb_item != 0)
	{
		d->map[d->player.y][d->player.x] = '0';
		d->player.y--;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	if (d->nb_item == 0 && d->map[d->player.y - 1][d->player.x] != '1')
	{
		d->player.y--;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->player.img.img,
		d->player.x * 64, d->player.y * 64);
	if (d->map[d->player.y + 1][d->player.x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->floor.img.img,
			d->player.x * 64, (d->player.y + 1) * 64);
}

void	ft_down_move(t_data *d)
{
	if (d->map[d->player.y + 1][d->player.x] == 'C')
	{
		d->map[d->player.y + 1][d->player.x] = '0';
		d->nb_item--;
	}
	if (d->map[d->player.y + 1][d->player.x] != '1'
		&& d->map[d->player.y + 1][d->player.x] != 'E' && d->nb_item != 0)
	{
		d->map[d->player.y][d->player.x] = '0';
		d->player.y++;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	if (d->nb_item == 0 && d->map[d->player.y + 1][d->player.x] != '1')
	{
		d->player.y++;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->player.img.img,
		d->player.x * 64, d->player.y * 64);
	if (d->map[d->player.y - 1][d->player.x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->floor.img.img,
			d->player.x * 64, (d->player.y - 1) * 64);
}

void	ft_left_move(t_data *d)
{
	if (d->map[d->player.y][d->player.x - 1] == 'C')
	{
		d->map[d->player.y][d->player.x - 1] = '0';
		d->nb_item--;
	}
	if (d->map[d->player.y][d->player.x - 1] != '1'
		&& d->map[d->player.y][d->player.x - 1] != 'E' && d->nb_item != 0)
	{
		d->map[d->player.y][d->player.x] = '0';
		d->player.x--;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	if (d->nb_item == 0 && d->map[d->player.y][d->player.x - 1] != '1')
	{
		d->player.x--;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->player.img.img,
		d->player.x * 64, d->player.y * 64);
	if (d->map[d->player.y][d->player.x + 1] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->floor.img.img,
			(d->player.x + 1) * 64, d->player.y * 64);
}

void	ft_right_move(t_data *d)
{
	if (d->map[d->player.y][d->player.x + 1] == 'C')
	{
		d->map[d->player.y][d->player.x + 1] = '0';
		d->nb_item--;
	}
	if (d->map[d->player.y][d->player.x + 1] != '1'
		&& d->map[d->player.y][d->player.x + 1] != 'E' && d->nb_item != 0)
	{
		d->map[d->player.y][d->player.x] = '0';
		d->player.x++;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	if (d->nb_item == 0 && d->map[d->player.y][d->player.x + 1] != '1')
	{
		d->player.x++;
		d->step++;
		ft_printf("%d\n", d->step);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->player.img.img,
		d->player.x * 64, d->player.y * 64);
	if (d->map[d->player.y][d->player.x - 1] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->floor.img.img,
			(d->player.x - 1) * 64, d->player.y * 64);
}
