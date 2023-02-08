/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:15:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/06 15:52:28 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_check_data(t_data *data, char *line, int fd)
{
	if (data->colors.floor_data == NULL || data->colors.ceiling_data == NULL
		|| data->wall.north_data == NULL || data->wall.south_data == NULL
		|| data->wall.west_data == NULL || data->wall.east_data == NULL)
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Missing data.", line, NULL);
	}
	ft_check_textures(data, line, fd);
	ft_check_colors(data, line, fd);
}

int	ft_map_begenning(char *line)
{
	int	i;

	i = 0;
	if (line[0] == ' ' || line[0] == '1' || line[0] == '0')
	{
		while (line[i] && line[i] != '1' && line[i] != '0')
			i++;
		if (i < (int)ft_strlen(line))
			return (1);
	}
	return (0);
}

void	ft_map_parsing(t_data *data, char *line, int fd)
{
	while (1)
	{
		if (!line)
			break ;
		data->map = ft_realloc_tab_char(data->map, line);
		line = simpler_gnl(fd);
	}
}
