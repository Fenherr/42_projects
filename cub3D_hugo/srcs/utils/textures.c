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

void	ft_set_texture(t_data *data)
{
	 int	i;
	 int	j;

	 data->wall.north.img = mlx_xpm_file_to_image(data->mlx,
		data->wall.north_path, &i, &j);
	data->wall.south.img = mlx_xpm_file_to_image(data->mlx,
		data->wall.south_path, &i, &j);
	data->wall.west.img = mlx_xpm_file_to_image(data->mlx,
		data->wall.west_path, &i, &j);
	data->wall.east.img = mlx_xpm_file_to_image(data->mlx,
		data->wall.east_path, &i, &j);
}
