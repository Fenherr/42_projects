/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:43:00 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/30 15:48:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_texture_data(t_data *data, char *line, char **tmp)
{
	if (!ft_strncmp(line, "NO ", 3))
		data->wall.north_path = ft_dup_path(tmp[1]);
	else if (!ft_strncmp(line, "SO ", 3))
		data->wall.south_path = ft_dup_path(tmp[1]);
	else if (!ft_strncmp(line, "WE ", 3))
		data->wall.west_path = ft_dup_path(tmp[1]);
	else if (!ft_strncmp(line, "EA ", 3))
		data->wall.east_path = ft_dup_path(tmp[1]);
	else if (!ft_strncmp(line, "F ", 2))
		data->colors.floor_data = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "C ", 2))
		data->colors.ceiling_data = ft_strdup(tmp[1]);
	else
	{
		if (*line != ' ' && *line != '1' && *line != '0'
			&& !ft_is_player(*line) && *line != '\n')
		{
			free(line);
			ft_free_array(tmp);
			ft_error_and_free("Invalid data detected", data);
		}
	}
}

void	ft_parse_data(t_data *data)
{
	int		fd;
	char	*line;
	char	**tmp;

	tmp = NULL;
	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	while (line)
	{
		if (ft_check_line(line))
		{
			free(line);
			ft_error_and_free("Empty line detected", data);
		}
		tmp = ft_split(line, ' ');
		ft_texture_data(data, line, tmp);
		ft_free_array(tmp);
		free(line);
		line = simpler_gnl(fd);
	}
	close (fd);
}

void	ft_check_caracters_map(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO", 2) && ft_strncmp(line, "SO", 2)
			&& ft_strncmp(line, "WE", 2) && ft_strncmp(line, "EA", 2)
			&& ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1)
			&& ft_strcmp(line, "\n"))
			ft_check_caracters_utils(data, line);
		free(line);
		line = simpler_gnl(fd);
	}
	close (fd);
}

static int	ft_check_texture_data_utils(char *texture)
{
	int		fd;
	char	*tmp;

	tmp = malloc(sizeof(char *) * (ft_strlen(texture)));
	ft_strcpy(tmp, texture);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		return (1);
	}
	close (fd);
	free(tmp);
	return (0);
}

void	ft_check_texture_data(t_data *data)
{
	if (data->wall.north_path == NULL || data->wall.south_path == NULL
		|| data->wall.west_path == NULL || data->wall.east_path == NULL)
		ft_error_and_free("We need a path for textures", data);
	else if (ft_check_texture_extension(data->wall.north_path)
		|| ft_check_texture_extension(data->wall.south_path)
		|| ft_check_texture_extension(data->wall.west_path)
		|| ft_check_texture_extension(data->wall.east_path))
		ft_error_and_free("We need a good path with a good extension", data);
	else if (ft_check_texture_data_utils(data->wall.north_path))
		ft_error_and_free(
			"The northern texture doesn't exist or is not available", data);
	else if (ft_check_texture_data_utils(data->wall.south_path))
		ft_error_and_free(
			"The southern texture doesn't exist or is not available", data);
	else if (ft_check_texture_data_utils(data->wall.west_path))
		ft_error_and_free(
			"The western texture doesn't exist or is not available", data);
	else if (ft_check_texture_data_utils(data->wall.east_path))
		ft_error_and_free(
			"The eastern texture doesn't exist or is not available", data);
}
