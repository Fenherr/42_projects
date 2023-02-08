/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:31:22 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/07 14:41:30 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_check_comma(char *color_data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color_data[i])
	{
		if (color_data[i] == ',' && color_data[i + 1] == ',')
			return (1);
		else if (color_data[i] == ',')
			count++;
		i++;
	}
	if (count > 2 || count < 2)
		return (1);
	return (0);
}

int	ft_check_last_nbr(char *color_data)
{
	char	**tmp;
	char	**tmp_color;

	tmp = ft_split(color_data, ' ');
	if (tmp == NULL)
	{
		ft_free_array(tmp);
		return (1);
	}
	tmp_color = ft_split(tmp[1], ',');
	if (tmp_color == NULL)
	{
		ft_free_array(tmp);
		ft_free_array(tmp_color);
		return (1);
	}
	if (!tmp_color[2])
	{
		ft_free_array(tmp);
		ft_free_array(tmp_color);
		return (1);
	}
	ft_free_array(tmp);
	ft_free_array(tmp_color);
	return (0);
}

static int	ft_check_digit(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (color[i] < '0' || color[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_limits(int color)
{
	return (color < 0 || color > 255);
}

int	ft_check_invalid_color(char *color_data)
{
	char	**tmp;
	char	**tmp_color;

	tmp = ft_split(color_data, ' ');
	tmp_color = ft_split(tmp[1], ',');
	if (ft_check_digit(tmp_color[0])
		|| ft_check_digit(tmp_color[1])
		|| ft_check_digit(tmp_color[2]))
	{
		ft_free_array(tmp);
		ft_free_array(tmp_color);
		return (1);
	}
	if (ft_check_limits(ft_atoi(tmp_color[0]))
		|| ft_check_limits(ft_atoi(tmp_color[1]))
		|| ft_check_limits(ft_atoi(tmp_color[2])))
	{
		ft_free_array(tmp);
		ft_free_array(tmp_color);
		return (1);
	}
	ft_free_array(tmp);
	ft_free_array(tmp_color);
	return (0);
}
