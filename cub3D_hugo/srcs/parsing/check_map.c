/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:57:22 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/04 14:13:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_check_wall_utils(t_data *data, int i, int j, int len)
{
	if (data->map[i][j] != ' ')
	{
		if (i == 0 && data->map[i][j] != '1')
			return (1);
		if (i == data->map_height - 1 && data->map[i][j] != '1')
			return (1);
		if (j == 0 && data->map[i][j] != '1')
			return (1);
		if (j == len && data->map[i][j] != '1')
			return (1);
	}
	return (0);
}

static int	ft_check_wall_map(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		len = ft_strlen(data->map[i]) - 2;
		while (j <= len)
		{
			if (ft_check_wall_utils(data, i, j, len))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_space_utils(t_data *data, int i, int j)
{
	if (data->map[i][j] == ' ')
	{
		if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != ' '
			&& data->map[i + 1][j] != '\n' && data->map[i + 1][j] != '\0')
			return (1);
		if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != ' '
			&& data->map[i - 1][j] != '\n' && data->map[i - 1][j] != '\0')
			return (1);
		if (j != 0)
		{
			if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != ' ')
				return (1);
			if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != ' ')
				return (1);
			if (ft_check_diagonal(data, i, j))
				return (1);
		}
	}
	return (0);
}

static int	ft_check_space(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < data->map_height - 1)
	{
		j = 0;
		len = ft_strlen(data->map[i]) - 2;
		while (j < len)
		{
			if (len > (int)ft_strlen(data->map[i + 1]) - 2
				|| len > (int)ft_strlen(data->map[i - 1]) - 2)
			{
				if (ft_if_high_len(data, i, j))
					return (1);
			}
			else
				if (ft_check_space_utils(data, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_map(t_data *data)
{
	if (ft_check_wall_map(data))
		ft_error_msg("Map not closed", NULL, data->map);
	else if (ft_check_space(data))
		ft_error_msg("Map not closed", NULL, data->map);
}
