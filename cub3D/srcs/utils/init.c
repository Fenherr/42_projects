/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/02/02 13:02:50 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/02 16:43:59 by ngrenoux         ###   ########.fr       */
=======
/*   Created: 2022/12/20 13:12:20 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/06 13:04:55 by ngrenoux         ###   ########.fr       */
>>>>>>> 53d5a2a963e11ce4909f9e4452414243feea8a93
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	check_map_extension(char *map_name)
{
	int		i;
	char	*extension;

	i = 0;
	while (map_name[i] != '.')
		i++;
	if (i == 0)
		ft_error_msg("A name is required for the map file.", NULL, NULL);
	extension = ft_strchr(map_name, '.');
	if (extension == NULL || ft_strcmp(extension, ".cub") != 0)
		ft_error_msg("Wrong extension file.", NULL, NULL);
}

void	ft_clear_data(t_data *data)
{
	data->map = NULL;
	data->map_height = 0;
<<<<<<< HEAD
=======
	data->error.nb_player = 0;
	data->error.dup_north = 0;
	data->error.dup_south = 0;
	data->error.dup_west = 0;
	data->error.dup_east = 0;
	data->error.dup_floor = 0;
	data->error.dup_ceiling = 0;
>>>>>>> 53d5a2a963e11ce4909f9e4452414243feea8a93
	data->colors.floor = 0;
	data->colors.ceiling = 0;
	data->colors.floor_data = NULL;
	data->colors.ceiling_data = NULL;
	data->wall.west_path = NULL;
	data->wall.east_path = NULL;
	data->wall.north_path = NULL;
	data->wall.south_path = NULL;
}

void	ft_init(t_data *data, char *map_name)
{
	check_map_extension(map_name);
	ft_clear_data(data);
	data->map_path = map_name;
}
