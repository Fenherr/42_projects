/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:24:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/17 15:10:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static size_t len_line(t_data *data)
{
	char *line;
	size_t len;
	int fd;

	len = 0;
	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	len = ft_strlen(line);
	free(line);
	close(fd);
	return (len);
}

static void ft_check_char_map(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
			ft_error_msg("Invalid character", line, NULL);
		if (line[i] == 'P')
			data->nb_player++;
		if (line[i] == 'C')
			data->nb_item++;
		if (line[i] == 'E')
			data->nb_exit++;
		i++;
	}
}

void ft_check_map(t_data *data)
{
	int fd;
	char *line;
	size_t len;

	len = len_line(data);
	fd = open(data->map_path, O_RDONLY);
	while ((line = simpler_gnl(fd)))
	{
		if (ft_strlen(line) != len)
			ft_error_msg("Wrong map width", line, NULL);
		ft_check_char_map(data, line);
		free(line);
	}
	ft_error_elm(data);
	close(fd);
}

void ft_check_wall(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map_width - 1)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			ft_error_msg("Map not closed", data->map_path, data->map);
		i++;
	}
	i = 0;
	while (i < data->map_height - 2)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 2] != '1')
			ft_error_msg("Map not closed", data->map_path, data->map);
		i++;
	}
}

void ft_check_if_solvable(t_data *data)
{
	// if (solve_map(data) == 1)
	ft_printf("%d", solve_map(data));
}