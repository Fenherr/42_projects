/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:05:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/09 10:37:50 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

static int	ft_check_digit(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] < '0' || tmp[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_extract_colors(char *color_data)
{
	int		color;
	char	**tmp;

	color = 0;
	tmp = ft_split(color_data, ',');
	if (ft_check_digit(tmp[0]) || ft_check_digit(tmp[1])
		|| ft_check_digit(tmp[2]))
		ft_error_msg("We need integer for colors !", NULL, tmp);
	if (ft_atoi(tmp[0]) < 0 || ft_atoi(tmp[1]) < 0 || ft_atoi(tmp[2]) < 0)
		ft_error_msg("Not negative integer for colors !", NULL, tmp);
	else if (ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[1]) > 255
		|| ft_atoi(tmp[2]) > 255)
		ft_error_msg("Not above 255 !", NULL, tmp);
	color = ft_create_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	ft_free_array(tmp);
	return (color);
}

void	ft_colors(t_data *data)
{
	data->colors.floor = ft_extract_colors(data->colors.floor_data);
	data->colors.ceiling = ft_extract_colors(data->colors.ceiling_data);
}
