/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:43:00 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/09 09:03:23 by ngrenoux         ###   ########.fr       */
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
		data->colors.floor_data = ft_strdup(tmp[1]);
	else if (!ft_strncmp(line, "C", 1))
		data->colors.ceiling_data = ft_strdup(tmp[1]);
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

	tmp = malloc(sizeof(char *) * (ft_strlen(texture) - 1));
	ft_strlcpy(tmp, texture, ft_strlen(texture));
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		free(tmp);
		return (1);
	}
	close (fd);
	free(tmp);
	return (0);
}

void	ft_check_texture_data(t_data *data)
{
	if (ft_check_texture_data_utils(data->wall.north_path))
		ft_error_msg("The northern texture does not exist", NULL, NULL);
	else if (ft_check_texture_data_utils(data->wall.south_path))
		ft_error_msg("The southern texture does not exist", NULL, NULL);
	else if (ft_check_texture_data_utils(data->wall.west_path))
		ft_error_msg("The western texture does not exist", NULL, NULL);
	else if (ft_check_texture_data_utils(data->wall.east_path))
		ft_error_msg("The eastern texture does not exist", NULL, NULL);
}
