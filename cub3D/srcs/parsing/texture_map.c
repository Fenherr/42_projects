/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:27:11 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/08 13:47:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_duplicate_map(t_data *data)
{
	int	i;

	i = 0;
	data->dup_map = ft_calloc((data->map_height + 1), sizeof(char *));
	while (data->map[i])
	{
		data->dup_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	data->dup_map[i] = NULL;
}

static void	ft_texture_map_high_len(t_data *data, int i, int j)
{
	if (ft_strlen(data->dup_map[i]) > ft_strlen(data->dup_map[i + 1]))
		if (data->dup_map[i][j] == '1' && (data->dup_map[i - 1][j] == '0'
			|| ft_is_player(data->dup_map[i - 1][j])))
			data->dup_map[i][j] = '2';
	if (ft_strlen(data->dup_map[i]) > ft_strlen(data->dup_map[i - 1])
		&& j < (int)ft_strlen(data->dup_map[i - 1]))
		if (data->dup_map[i][j] == '1' && (data->dup_map[i - 1][j] == '0'
			|| ft_is_player(data->dup_map[i - 1][j])))
			data->dup_map[i][j] = '2';
	if (data->dup_map[i][j] == '1' && (data->dup_map[i][j + 1] == '0'
		|| ft_is_player(data->dup_map[i][j + 1])))
		data->dup_map[i][j] = '3';
	if (j > 0 && data->dup_map[i][j] == '1' && (data->dup_map[i][j - 1] == '0'
		|| ft_is_player(data->dup_map[i][j - 1])))
		data->dup_map[i][j] = '4';
}

static void	ft_texture_map_util(t_data *data, int i, int j)
{
	if (data->dup_map[i][j] == '1' && (data->dup_map[i - 1][j] == '0'
		|| ft_is_player(data->dup_map[i - 1][j])))
		data->dup_map[i][j] = '2';
	if (data->dup_map[i][j] == '1' && (data->dup_map[i][j + 1] == '0'
		|| ft_is_player(data->dup_map[i][j + 1])))
		data->dup_map[i][j] = '3';
	if (j > 0 && data->dup_map[i][j] == '1' && (data->dup_map[i][j - 1] == '0'
		|| ft_is_player(data->dup_map[i][j - 1])))
		data->dup_map[i][j] = '4';
}

static void	ft_last_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->dup_map[data->map_height - 1][i])
	{
		if (data->dup_map[data->map_height - 1][i] == '1')
			data->dup_map[data->map_height - 1][i] = '2';
		i++;
	}
}

void	ft_texture_map(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	ft_duplicate_map(data);
	ft_check_corner(data);
	while (data->dup_map[i])
	{
		j = 0;
		len = ft_strlen(data->dup_map[i]);
		while (data->dup_map[i][j] && i < data->map_height - 1)
		{
			while (data->dup_map[i][j] == ' ')
				j++;
			if (len > (int)ft_strlen(data->dup_map[i + 1])
				|| len > (int)ft_strlen(data->dup_map[i - 1]))
				ft_texture_map_high_len(data, i, j);
			else
				ft_texture_map_util(data, i, j);
			j++;
		}
		i++;
	}
	ft_last_line(data);
}
