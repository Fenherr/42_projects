/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:18:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/27 11:25:36 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_check_duplicate(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2))
			data->error.dup_north++;
		if (!ft_strncmp(line, "SO", 2))
			data->error.dup_south++;
		if (!ft_strncmp(line, "WE", 2))
			data->error.dup_west++;
		if (!ft_strncmp(line, "EA", 2))
			data->error.dup_east++;
		if (!ft_strncmp(line, "F", 1))
			data->error.dup_floor++;
		if (!ft_strncmp(line, "C", 1))
			data->error.dup_ceiling++;
		free(line);
		line = simpler_gnl(fd);
	}
	close(fd);
}

static void	ft_is_dup(t_data *data)
{
	ft_check_duplicate(data);
	if (data->error.dup_ceiling != 1 || data->error.dup_east != 1
		|| data->error.dup_floor != 1 || data->error.dup_north != 1
		|| data->error.dup_south != 1 || data->error.dup_west != 1)
		ft_error_msg("One data or more is duplicate", NULL, NULL);
}

void	ft_check_data(t_data *data)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	if (line == NULL)
		ft_error_msg("Empty file", line, NULL);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
			|| !ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
			count++;
		free(line);
		line = simpler_gnl(fd);
	}
	if (count < 6)
		ft_error_msg("Missing data", line, NULL);
	else if (count > 6)
		ft_error_msg("Too much data", line, NULL);
	ft_is_dup(data);
	close(fd);
}

void	ft_check_caracters_utils(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != '\n' && line[i] == 'N' && line[i] == 'S'
			&& line[i] == 'W' && line[i] == 'E')
			ft_error_msg("Invalid character", line, NULL);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			data->error.nb_player++;
		i++;
	}
}
