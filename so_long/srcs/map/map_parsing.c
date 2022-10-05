/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:27:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/05 14:33:23 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_map_len(t_data *data)
{
	int	fd;
	char	*line;

	fd = open(data->map_name, O_RDONLY);
	while ((line = simpler_gnl(fd)))
	{
		data->map_width++;
		data->map_length = ft_strlen(line);
	}
	ft_printf("La largeur de la map est : %d\n", data->map_width);
	ft_printf("La longueur de la map est : %d\n", data->map_length);
	close (fd);
}
