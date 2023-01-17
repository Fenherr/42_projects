/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:39:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/10 14:57:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_get_texture(t_data *data)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	data->wall.e = (int *)mlx_get_data_addr(data->wall.east.img,
			&pixel_bits, &line_bytes, &endian);
	data->wall.s = (int *)mlx_get_data_addr(data->wall.south.img,
			&pixel_bits, &line_bytes, &endian);
	data->wall.n = (int *)mlx_get_data_addr(data->wall.north.img,
			&pixel_bits, &line_bytes, &endian);
	data->wall.w = (int *)mlx_get_data_addr(data->wall.west.img,
			&pixel_bits, &line_bytes, &endian);
}

void	ft_set_texture(t_data *data)
{
	data->wall.north.img = mlx_xpm_file_to_image(data->mlx,
			data->wall.north_path, &data->wall.north.width,
			&data->wall.north.height);
	data->wall.south.img = mlx_xpm_file_to_image(data->mlx,
			data->wall.south_path, &data->wall.south.width,
			&data->wall.south.height);
	data->wall.west.img = mlx_xpm_file_to_image(data->mlx,
			data->wall.west_path, &data->wall.west.width,
			&data->wall.west.height);
	data->wall.east.img = mlx_xpm_file_to_image(data->mlx,
			data->wall.east_path, &data->wall.east.width,
			&data->wall.east.height);
	ft_get_texture(data);
}
