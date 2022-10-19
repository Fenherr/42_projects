/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:49:03 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/19 15:56:32 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_up_move(t_data *data)
{
	if (data->map[data->player.y - 1][data->player.x] == 'C')
	{
		data->map[data->player.y - 1][data->player.x] = '0';
		data->nb_item--;
	}
	if (data->map[data->player.y - 1][data->player.x] != '1'
		&& data->map[data->player.y - 1][data->player.x] != 'E')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y--;
		data->step++;
		ft_printf("%d\n", data->step);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.img.img,
		data->player.x * 64, data->player.y * 64);
	if (data->map[data->player.y + 1][data->player.x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor.img.img,
			data->player.x * 64, (data->player.y + 1) * 64);
}

void	ft_down_move(t_data *data)
{
	if (data->map[data->player.y + 1][data->player.x] == 'C')
	{
		data->map[data->player.y + 1][data->player.x] = '0';
		data->nb_item--;
	}
	if (data->map[data->player.y + 1][data->player.x] != '1'
		&& data->map[data->player.y + 1][data->player.x] != 'E')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y++;
		data->step++;
		ft_printf("%d\n", data->step);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.img.img,
		data->player.x * 64, data->player.y * 64);
	if (data->map[data->player.y - 1][data->player.x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor.img.img,
			data->player.x * 64, (data->player.y - 1) * 64);
}

void	ft_left_move(t_data *data)
{
	if (data->map[data->player.y][data->player.x - 1] == 'C')
	{
		data->map[data->player.y][data->player.x - 1] = '0';
		data->nb_item--;
	}
	if (data->map[data->player.y][data->player.x - 1] != '1'
		&& data->map[data->player.y][data->player.x - 1] != 'E')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x--;
		data->step++;
		ft_printf("%d\n", data->step);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.img.img,
		data->player.x * 64, data->player.y * 64);
	if (data->map[data->player.y][data->player.x + 1] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor.img.img,
			(data->player.x + 1) * 64, data->player.y * 64);
}

void	ft_right_move(t_data *data)
{
	if (data->map[data->player.y][data->player.x + 1] == 'C')
	{
		data->map[data->player.y][data->player.x + 1] = '0';
		data->nb_item--;
	}
	if (data->map[data->player.y][data->player.x + 1] != '1'
		&& data->map[data->player.y][data->player.x + 1] != 'E')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x++;
		data->step++;
		ft_printf("%d\n", data->step);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.img.img,
		data->player.x * 64, data->player.y * 64);
	if (data->map[data->player.y][data->player.x - 1] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor.img.img,
			(data->player.x - 1) * 64, data->player.y * 64);
}