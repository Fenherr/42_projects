/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:46:43 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/06 15:43:28 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_put_pixel(t_data *data, int *colorized)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = data->colors.ceiling;
	while (j < WIN_HEIGHT)
	{
		if (j == WIN_HEIGHT / 2)
			color = data->colors.floor;
		while (i < WIN_WIDTH)
		{
			colorized[j * WIN_WIDTH + i] = color;
			i++;
		}
		j++;
		i = 0;
	}
}
