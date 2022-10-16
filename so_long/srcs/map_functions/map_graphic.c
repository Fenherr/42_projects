/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:03:23 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/16 21:31:26 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	place_img_in_game(t_data *data)
{
	int	i;
	int	j;

	data->floor.img.img = mlx_xpm_file_to_image(data->mlx,
		"resources/tiles/floor.xpm", &i, &j);
	data->wall.img.img = mlx_xpm_file_to_image(data->mlx,
		"resources/tiles/wall.xpm", &i, &j);
	data->item.img.img = mlx_xpm_file_to_image(data->mlx,
		"resources/tiles/item.xpm", &i, &j);
	data->exit.img.img = mlx_xpm_file_to_image(data->mlx,
		"resources/tiles/door_close.xpm", &i, &j);
}

void	ft_graphics(t_data *data)
{
	int	height;
	int	length;

	height = 0;
	while (height < data->map_height)
	{
		length = 0;
		while (data->map[height][length])
		{
			if (data->map[height][length] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall.img.img,	length * 32, height * 32);
			if (data->map[height][length] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->floor.img.img, length * 32, height * 32);
			if (data->map[height][length] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit.img.img, length * 32, height * 32);
			if (data->map[height][length] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->item.img.img, length * 32, height * 32);
			length++;
		}
		height++;
	}
}