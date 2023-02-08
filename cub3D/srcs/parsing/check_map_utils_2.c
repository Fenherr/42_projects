/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:15:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/08 12:18:00 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_check_diagonal(t_data *data, int i, int j)
{
	if (data->map[i + 1][j + 1] != '1' && data->map[i + 1][j + 1] != ' '
		&& data->map[i + 1][j + 1] != '\n' && data->map[i + 1][j + 1] != '\0')
		return (1);
	if (data->map[i - 1][j + 1] != '1' && data->map[i - 1][j + 1] != ' '
		&& data->map[i - 1][j + 1] != '\n' && data->map[i - 1][j + 1] != '\0')
		return (1);
	if (data->map[i + 1][j - 1] != '1' && data->map[i + 1][j - 1] != ' '
		&& data->map[i + 1][j - 1] != '\n' && data->map[i + 1][j - 1] != '\0')
		return (1);
	if (data->map[i - 1][j - 1] != '1' && data->map[i - 1][j - 1] != ' '
		&& data->map[i - 1][j - 1] != '\n' && data->map[i - 1][j - 1] != '\0')
		return (1);
	return (0);
}

int	ft_check_space_utils(t_data *data, int i, int j)
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

int	ft_check_wall_utils(t_data *data, int i, int j, int len)
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
