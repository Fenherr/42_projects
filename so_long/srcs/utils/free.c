/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/20 11:43:55 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free(char *str, char **arr)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
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

void	ft_free_mtx(int **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
	mtx = NULL;
}

void	ft_free_all(t_data *data)
{
	ft_free(NULL, data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
