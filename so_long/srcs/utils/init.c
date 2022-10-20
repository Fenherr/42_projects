/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:36:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/20 13:10:09 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_map_extension(char *map_name)
{
	char	*extension;

	extension = ft_strchr(map_name, '.');
	if (extension == NULL || ft_strcmp(extension, ".ber") != 0)
		ft_error_msg("Wrong extension file", NULL, NULL);
}

void	ft_init(t_data *data, char *map_name)
{
	int	fd;

	check_map_extension(map_name);
	data->step = 0;
	data->nb_exit = 0;
	data->nb_item = 0;
	data->nb_player = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->map_path = map_name;
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(map_name);
		exit(1);
	}
	close (fd);
	data->player.x = 0;
	data->player.y = 0;
}
