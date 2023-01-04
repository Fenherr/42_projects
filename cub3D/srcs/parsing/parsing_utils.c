/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:43:00 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/03 16:24:39 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_texture_data(t_data *data, char *line, char **tmp)
{
	if (!ft_strncmp(line, "NO", 2))
		data->wall.north_path = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "SO", 2))
		data->wall.south_path = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "WE", 2))
		data->wall.west_path = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "EA", 2))
		data->wall.east_path = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "F", 1))
		data->colors.floor = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "C", 1))
		data->colors.ceiling = ft_strdup(tmp[1]);
}

void	ft_parse_data(t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	char	**tmp;

	i = 0;
	tmp = NULL;
	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	while (line)
	{
		tmp = ft_split(line, ' ');
		ft_texture_data(data, line, tmp);
		ft_free_array(tmp);
		free(line);
		line = simpler_gnl(fd);
		i++;
	}
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
