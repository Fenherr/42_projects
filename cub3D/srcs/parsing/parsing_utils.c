/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:15:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/05 13:45:09 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_check_data(t_data *data, char *line, int fd)
{
	if (data->colors.floor_data == NULL || data->colors.ceiling_data == NULL
		|| data->wall.north_path == NULL || data->wall.south_path == NULL
		|| data->wall.west_path == NULL || data->wall.east_path == NULL)
	{
		close (fd);
		ft_free_all(data);
		ft_error_msg("Missing data", line, NULL);
	}
}

int	ft_map_begenning(char *line)
{
	int i;

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

void	ft_parsing_map(t_data *data, char *line, int fd)
{
	(void)fd;
	data->map = ft_realloc_tab_char(data->map, line);
	for (int i = 0; data->map[i]; i++)
		printf("%s", data->map[i]);
}
