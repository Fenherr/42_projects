/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:59:17 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/07 11:20:07 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_extract_texture_path(t_data *data, char *texture_data)
{
	char	**tmp;

	tmp = ft_split(texture_data, ' ');
	if (!ft_strcmp(tmp[0], "NO"))
		data->wall.north_path = ft_strdup(tmp[1]);
	if (!ft_strcmp(tmp[0], "SO"))
		data->wall.south_path = ft_strdup(tmp[1]);
	if (!ft_strcmp(tmp[0], "WE"))
		data->wall.west_path = ft_strdup(tmp[1]);
	if (!ft_strcmp(tmp[0], "EA"))
		data->wall.east_path = ft_strdup(tmp[1]);
	ft_free_array(tmp);
}

static int	ft_check_texture_path_utils(char *texture_path)
{
	int	i;

	i = 0;
	while (texture_path[i] == 'N' || texture_path[i] == 'S'
		|| texture_path[i] == 'W' || texture_path[i] == 'E'
		|| texture_path[i] == 'A' || texture_path[i] == 'O'
		|| texture_path[i] == ' ')
		i++;
	if (texture_path[i] == '\0')
		return (1);
	return (0);
}

static void	ft_check_texture_path(t_data *data, char *line, int fd)
{
	if (ft_check_texture_path_utils(data->wall.north_data)
		|| ft_check_texture_path_utils(data->wall.south_data)
		|| ft_check_texture_path_utils(data->wall.west_data)
		|| ft_check_texture_path_utils(data->wall.east_data))
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Texture path not found.", line, NULL);
	}
}

static int	ft_check_texture_utils(char *texture_data)
{
	char	**tmp;
	char	*extension;
	int		fd;

	tmp = ft_split(texture_data, ' ');
	extension = ft_strrchr(tmp[1], '.');
	fd = open(tmp[1], O_RDONLY);
	if (fd == -1)
	{
		ft_free_array(tmp);
		return (2);
	}
	else if (extension == NULL || ft_strcmp(extension, ".xpm"))
	{
		ft_free_array(tmp);
		return (1);
	}
	close (fd);
	ft_free_array(tmp);
	return (0);
}

void	ft_check_textures(t_data *data, char *line, int fd)
{
	ft_check_texture_path(data, line, fd);
	if (ft_check_texture_utils(data->wall.north_data) == 1
		|| ft_check_texture_utils(data->wall.south_data) == 1
		|| ft_check_texture_utils(data->wall.west_data) == 1
		|| ft_check_texture_utils(data->wall.east_data) == 1)
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Wrong texture extension.", line, NULL);
	}
	else if (ft_check_texture_utils(data->wall.north_data) == 2
		|| ft_check_texture_utils(data->wall.south_data) == 2
		|| ft_check_texture_utils(data->wall.west_data) == 2
		|| ft_check_texture_utils(data->wall.east_data) == 2)
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Texture not found.", line, NULL);
	}
	ft_extract_texture_path(data, data->wall.north_data);
	ft_extract_texture_path(data, data->wall.south_data);
	ft_extract_texture_path(data, data->wall.west_data);
	ft_extract_texture_path(data, data->wall.east_data);
}
