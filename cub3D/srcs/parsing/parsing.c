/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:04:19 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/12/27 13:37:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_map_len(t_data *data)
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
			data->map_height++;
		free(line);
		line = simpler_gnl(fd);
	}
	close (fd);
}

static void	ft_map_parsing(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	ft_map_len(data);
	if (data->map_height == 0)
		ft_error_msg("Missing map", NULL, NULL);
	fd = open(data->map_path, O_RDONLY);
	data->map = ft_calloc((data->map_height + 1), sizeof(char *));
	line = simpler_gnl(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO", 2) && ft_strncmp(line, "SO", 2)
			&& ft_strncmp(line, "WE", 2) && ft_strncmp(line, "EA", 2)
			&& ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1)
			&& ft_strcmp(line, "\n"))
			data->map[++i] = ft_strdup(line);
		free(line);
		line = simpler_gnl(fd);
	}
	close (fd);
}

void	ft_parsing(t_data *data)
{
	ft_check_data(data);
	ft_parse_data(data);
	ft_check_caracters_map(data);
	if (data->error.nb_player != 1)
		ft_error_msg("We need one and ONLY one player please !", NULL, NULL);
	ft_map_parsing(data);
	ft_check_map(data);
}