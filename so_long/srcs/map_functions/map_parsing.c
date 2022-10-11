/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:27:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/11 13:19:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_map_len(t_data *data)
{
	int	fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	line = simpler_gnl(fd);
	while (line)
	{
		data->map_height++;
		data->map_length = ft_strlen(line);
		free(line);
		line = simpler_gnl(fd);
	}
	close (fd);
}

void	ft_map_parsing(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	ft_check_map(data);
	ft_map_len(data);
	fd = open(data->map_path, O_RDONLY);
	data->map = malloc((data->map_height + 1 ) * sizeof(char *));
	line = simpler_gnl(fd);
	while (line)
	{
		data->map[i] = ft_strdup(line);
		free(line);
		line = simpler_gnl(fd);
		i++;
	}
	data->map[i] = NULL;
	close (fd);
	ft_check_wall(data);
}
