/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:27:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/10 13:57:02 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_map_len(t_data *data)
{
	int	fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	while ((line = simpler_gnl(fd)))
	{
		data->map_height++;
		data->map_length = ft_strlen(line);
	}
	close (fd);
	free(line);
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
	data->map = malloc(data->map_height * sizeof(char *));
	line = simpler_gnl(fd);
	while (line)
	{
		data->map[i] = ft_strdup(line);
		i++;
		line = simpler_gnl(fd);
	}
	close (fd);
	free(line);
}
