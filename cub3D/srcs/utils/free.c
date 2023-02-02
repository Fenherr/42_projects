/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:31:40 by ngrenoux          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/02 15:57:21 by ngrenoux         ###   ########.fr       */
=======
/*   Updated: 2023/01/06 13:31:38 by ngrenoux         ###   ########.fr       */
>>>>>>> 53d5a2a963e11ce4909f9e4452414243feea8a93
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
	free(data->wall.north_path);
	free(data->wall.south_path);
	free(data->wall.west_path);
	free(data->wall.east_path);
	free(data->colors.floor_data);
	free(data->colors.ceiling_data);
}
