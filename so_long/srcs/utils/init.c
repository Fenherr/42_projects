/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:36:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/18 15:59:16 by ngrenoux         ###   ########.fr       */
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
	check_map_extension(map_name);
	data->nb_exit = 0;
	data->nb_item = 0;
	data->nb_player = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->map_path = ft_strjoin("./maps/", map_name);
	if (open(data->map_path, O_RDONLY) == -1)
		ft_error_msg("File not found", data->map_path, NULL);
	data->player.x = 0;
	data->player.y = 0;
}
