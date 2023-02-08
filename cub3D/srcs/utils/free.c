/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:31:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/08 13:11:13 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	ft_free_all(t_data *data)
{
	free(data->wall.north_data);
	free(data->wall.south_data);
	free(data->wall.west_data);
	free(data->wall.east_data);
	free(data->wall.north_path);
	free(data->wall.south_path);
	free(data->wall.west_path);
	free(data->wall.east_path);
	free(data->colors.floor_data);
	free(data->colors.ceiling_data);
}

void	ft_close_and_free(int fd, t_data *data)
{
	close (fd);
	ft_free_all(data);
}
