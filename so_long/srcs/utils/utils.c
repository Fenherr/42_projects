/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:40:31 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/19 16:18:48 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->exit.img.img);
	mlx_destroy_image(data->mlx, data->wall.img.img);
	mlx_destroy_image(data->mlx, data->item.img.img);
	mlx_destroy_image(data->mlx, data->floor.img.img);
	mlx_destroy_image(data->mlx, data->player.img.img);
}

int	ft_exit(t_data *data)
{
	destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data->map_path, data->map);
	free(data->mlx);
	ft_printf("Good bye !\n");
	exit(1);
	return (0);
}

int	ft_exit_if_win(t_data *data)
{
	destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data->map_path, data->map);
	free(data->mlx);
	ft_printf("Congratulation ! You win !\n");
	exit(1);
	return (0);
}

void	ft_search_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height - 1)
	{
		j = 0;
		while (data->map[i][j] != 'P' && j < data->map_width - 1)
			j++;
		if (data->map[i][j] == 'P')
		{
			data->player.x = j;
			data->player.y = i;
		}
		i++;
	}
}

void	ft_search_exit_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height - 1)
	{
		j = 0;
		while (data->map[i][j] != 'E' && j < data->map_width - 1)
			j++;
		if (data->map[i][j] == 'E')
		{
			data->exit.x = j;
			data->exit.y = i;
		}
		i++;
	}
}
