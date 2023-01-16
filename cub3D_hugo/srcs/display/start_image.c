/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:21:52 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/13 13:23:53 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	*ft_create_image(t_data *data)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	*colorized;

	data->image[0].img = mlx_new_image(data->mlx,
			WIN_WIDTH, WIN_HEIGHT);
	colorized = (int *)mlx_get_data_addr(data->image[0].img,
			&pixel_bits, &line_bytes, &endian);
	return (colorized);
}

int	*ft_create_minimap(t_data *data)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	*minimap;

	data->image[1].img = mlx_new_image(data->mlx,
			360, 200);
	minimap = (int *)mlx_get_data_addr(data->image[1].img,
			&pixel_bits, &line_bytes, &endian);
	return (minimap);
}
