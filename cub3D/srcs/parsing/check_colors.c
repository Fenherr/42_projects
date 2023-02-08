/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:14:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/07 13:39:48 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

static int	ft_check_colors_utils(char *colors)
{
	int	i;

	i = 0;
	while (colors[i] == 'F' || colors[i] == 'C'
		|| colors[i] == ' ')
		i++;
	if (colors[i] == '\0')
		return (1);
	if (ft_check_comma(colors)
		|| ft_check_last_nbr(colors)
		|| ft_check_invalid_color(colors))
		return (2);
	return (0);
}

static int	ft_extract_colors(char *color_data)
{
	char	**tmp;
	char	**tmp_color;
	int		color;

	tmp = ft_split(color_data, ' ');
	tmp_color = ft_split(tmp[1], ',');
	color = ft_create_rgb(ft_atoi(tmp_color[0]), ft_atoi(tmp_color[1]),
			ft_atoi(tmp_color[1]));
	ft_free_array(tmp);
	ft_free_array(tmp_color);
	return (color);
}

void	ft_check_colors(t_data *data, char *line, int fd)
{
	if (ft_check_colors_utils(data->colors.floor_data) == 1
		|| ft_check_colors_utils(data->colors.ceiling_data) == 1)
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Color not found.", line, NULL);
	}
	if (ft_check_colors_utils(data->colors.floor_data) == 2
		|| ft_check_colors_utils(data->colors.ceiling_data) == 2)
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Incorrect rgb settings.", line, NULL);
	}
	data->colors.floor = ft_extract_colors(data->colors.floor_data);
	data->colors.ceiling = ft_extract_colors(data->colors.ceiling_data);
}
