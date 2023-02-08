/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:42:50 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/08 14:36:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_check_invalid_char(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0'
			&& !ft_is_player(str[i]) && str[i] != '\n')
			return (1);
		if (ft_is_player(str[i]))
			data->nb_player++;
		i++;
	}
	return (0);
}

static int	ft_check_around_zero(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map_height - 1)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (ft_check_around(data->map, i, j))
					return (1);
			}
			j++;
		}
		i++;
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
			else if (ft_check_space_utils(data, i, j))
				return (1);
			j++;
		}
		i++;
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

void	ft_check_map(t_data *data, int fd)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] == '\n')
		{
			ft_close_and_free(fd, data);
			ft_error_msg("Empty line detected.", NULL, data->map);
		}
		if (ft_check_invalid_char(data->map[i], data))
		{
			ft_close_and_free(fd, data);
			ft_error_msg("Invalid character detected.", NULL, data->map);
		}
		i++;
	}
	if (ft_check_around_zero(data) || ft_check_space(data)
		|| ft_check_wall_map(data))
	{
		ft_close_and_free(fd, data);
		ft_error_msg("Map not closed.", NULL, data->map);
	}
}
