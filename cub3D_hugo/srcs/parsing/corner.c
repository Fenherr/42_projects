/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:39:02 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/13 16:08:25 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_corner_high_len(t_data *data, int i, int j)
{
	int	count;

	count = 0;
	if (j > (int)ft_strlen(data->dup_map[i - 1]))
	{
		if (j > 0 && data->dup_map[i][j - 1] == '0')
			count++;
		if (data->dup_map[i][j + 1] == '0')
			count++;
		if (data->dup_map[i + 1][j] == '0')
			count++;
	}
	if (j > (int)ft_strlen(data->dup_map[i + 1]))
	{
		if (j > 0 && data->dup_map[i][j - 1] == '0')
			count++;
		if (data->dup_map[i][j + 1] == '0')
			count++;
		if (data->dup_map[i - 1][j] == '0')
			count++;
	}
	return (count);
}

int	ft_corner_util(t_data *data, int i, int j)
{
	int	count;

	count = 0;
	if (j > 0 && data->dup_map[i][j - 1] == '0')
		count++;
	if (data->dup_map[i][j + 1] == '0')
		count++;
	if (data->dup_map[i - 1][j] == '0')
		count++;
	if (data->dup_map[i + 1][j] == '0')
		count++;
	return (count);
}

void	ft_corner(t_data *data, int i, int j, int index)
{
	int	count;

	count = 0;
	if (index == 1)
		count = ft_corner_high_len(data, i, j);
	else
		count = ft_corner_util(data, i, j);
	if (count == 2)
		data->dup_map[i][j] = '5';
	else if (count == 3)
		data->dup_map[i][j] = '6';
	else if (count == 4)
		data->dup_map[i][j] = '7';
}

void	ft_check_corner(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->dup_map[i])
	{
		j = 0;
		while (data->dup_map[i][j] && i < data->map_height - 1)
		{
			if (data->dup_map[i][j] == '1')
			{
				if (j > (int)ft_strlen(data->dup_map[i + 1])
					|| j > (int)ft_strlen(data->dup_map[i - 1]))
					ft_corner(data, i, j, 1);
				else
					ft_corner(data, i, j, 0);
			}
			j++;
		}
		i++;
	}
}
