/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:44:45 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/06 15:41:46 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_to_see(t_data *data)
{
	int		i;
	double	angle;
	double	fovtot;

	for(i = 0; data->dup_map[i]; i++)
       	 printf("%s", data->dup_map[i]);
	if (data->moove == 0)
		return ;
	i = 0;
	data->square = 0;
	if (data->view - FOV < 0)
		angle = 12 + (data->view - FOV);
	else
		angle = data->view - FOV;
	if (i < WIN_WIDTH)
		ft_put_pixel(data, data->screen);
	fovtot = 2.0 / WIN_WIDTH;
	while (i < WIN_WIDTH)
	{
		ft_raycast(data, angle);
		if (angle + fovtot >= 12)
			angle = 0;
		angle = angle + fovtot;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image[0].img, 0, 0);
}
