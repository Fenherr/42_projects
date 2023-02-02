/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:55:25 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/02 18:16:08 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_parse_texture(char **data, char *line)
{
	if (*data == NULL)
		*data = ft_clean_dup(line);
	else
		return (1);
	return (0);
}

static int	ft_parse_data(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (ft_parse_texture(&data->wall.north_path, line));
	else if (!ft_strncmp(line, "SO ", 3))
		return (ft_parse_texture(&data->wall.south_path, line));
	else if (!ft_strncmp(line, "WE ", 3))
		return (ft_parse_texture(&data->wall.west_path, line));
	else if (!ft_strncmp(line, "EA ", 3))
		return (ft_parse_texture(&data->wall.east_path, line));
	else if (!ft_strncmp(line, "F ", 2))
		return (ft_parse_texture(&data->colors.floor_data, line));
	else if (!ft_strncmp(line, "C ", 2))
		return (ft_parse_texture(&data->colors.ceiling_data, line));
	return (0);
}

static void	ft_parsing_utils(t_data *data, char *line, int fd)
{
	if (ft_parse_data(data, line))
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Duplicate data detected.", line, NULL);
	}
}

void	ft_parsing(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
		ft_error_msg("Unable to open the map file.", NULL, NULL);
	line = simpler_gnl(fd);
	if (line == NULL)
		ft_error_msg("Empty file.", line, NULL);
	while (line)
	{
		ft_parsing_utils(data, line, fd);
		free(line);
		line = simpler_gnl(fd);
	}
	printf("%s\n", data->wall.north_path);
	printf("%s\n", data->wall.south_path);
	printf("%s\n", data->wall.west_path);
	printf("%s\n", data->wall.east_path);
	printf("%s\n", data->colors.floor_data);
	printf("%s\n", data->colors.ceiling_data);
	close (fd);
}
