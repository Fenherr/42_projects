/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:53:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/09 09:02:33 by ngrenoux         ###   ########.fr       */
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

static int	ft_check_diagonal_high_len(t_data *data, int i, int j)
{
	if (ft_strlen(data->map[i]) - 2 > ft_strlen(data->map[i - 1]) - 2)
	{
		if (data->map[i + 1][j + 1] != '1' && data->map[i + 1][j + 1] != ' '
			&& data->map[i + 1][j + 1] != '\n'
			&& data->map[i + 1][j + 1] != '\0')
			return (1);
		if (data->map[i + 1][j - 1] != '1' && data->map[i + 1][j - 1] != ' '
			&& data->map[i + 1][j - 1] != '\n'
			&& data->map[i + 1][j - 1] != '\0')
			return (1);
	}
	else if (ft_strlen(data->map[i]) - 2 > ft_strlen(data->map[i + 1]) - 2)
	{
		if (data->map[i - 1][j + 1] != '1' && data->map[i - 1][j + 1] != ' '
			&& data->map[i - 1][j + 1] != '\n'
			&& data->map[i - 1][j + 1] != '\0')
			return (1);
		if (data->map[i - 1][j - 1] != '1' && data->map[i - 1][j - 1] != ' '
			&& data->map[i - 1][j - 1] != '\n'
			&& data->map[i - 1][j - 1] != '\0')
			return (1);
	}
	return (0);
}

int	ft_if_high_len(t_data *data, int i, int j)
{
	if (data->map[i][j] == ' ')
	{
		if (ft_strlen(data->map[i]) - 2 > ft_strlen(data->map[i - 1]) - 2)
		{
			if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != ' '
				&& data->map[i + 1][j] != '\n' && data->map[i + 1][j] != '\0')
				return (1);
		}
		else if (ft_strlen(data->map[i]) - 2 > ft_strlen(data->map[i + 1]) - 2)
			if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != ' '
				&& data->map[i - 1][j] != '\n' && data->map[i - 1][j] != '\0')
				return (1);
		if (j != 0)
		{
			if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != ' ')
				return (1);
			if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != ' ')
				return (1);
			if (ft_check_diagonal_high_len(data, i, j))
				return (1);
		}
	}
	return (0);
}
