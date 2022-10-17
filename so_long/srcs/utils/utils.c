/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:40:31 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/17 13:25:17 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->exit.img.img);
	mlx_destroy_image(data->mlx, data->floor.img.img);
	mlx_destroy_image(data->mlx, data->wall.img.img);
	mlx_destroy_image(data->mlx, data->item.img.img);
}

int ft_exit(t_data *data)
{
	destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data->map_path, data->map);
	free(data->mlx);
	exit(1);
	return (0);
}