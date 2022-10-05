/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:24:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/05 14:11:15 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static size_t	len_line(t_data *data)
{
	char	*line;
	size_t	len;
	int		fd;
	
	len = 0;
	fd = open(data->map_name, O_RDONLY);
	line = simpler_gnl(fd);
	len = ft_strlen(line);
	close (fd);
	return (len);
}

static void	ft_check_char_map(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
			ft_error_msg("Invalid character");
		if (line[i] == 'P')
			data->player++;
		if (line[i] == 'C')
			data->item++;
		if (line[i] == 'E')
			data->exit++;
		i++;
	}
}

void	ft_check_map(t_data *data)
{
	int		fd;
	char	*line;
	size_t	len;

	len = len_line(data);
	fd = open(data->map_name, O_RDONLY);
	while ((line = simpler_gnl(fd)))
	{
		if (ft_strlen(line) != len)
			ft_error_msg("Wrong map length");
		ft_check_char_map(data, line);
	}
	ft_error_elm(data);
	close (fd);
}