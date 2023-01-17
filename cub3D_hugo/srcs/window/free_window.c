/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:49:41 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/13 09:30:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_free_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image[0].img);
	mlx_destroy_image(data->mlx, data->image[1].img);
	mlx_destroy_image(data->mlx, data->image[2].img);
	mlx_destroy_image(data->mlx, data->wall.north.img);
	mlx_destroy_image(data->mlx, data->wall.south.img);
	mlx_destroy_image(data->mlx, data->wall.east.img);
	mlx_destroy_image(data->mlx, data->wall.west.img);
}

void	ft_free(t_data *data)
{
	ft_free_image(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_array(data->map);
	ft_free_array(data->dup_map);
	ft_free_all(data);
	exit (0);
}
