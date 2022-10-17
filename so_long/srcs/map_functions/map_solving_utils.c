/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/17 14:29:29 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	**allocate_solving_mtx(t_data *data)
{
	int	i;
	int	**solving_mtx;

	i = 0;
	solving_mtx = (int **)ft_calloc((data->map_height + 1), sizeof(int *));
	if (!solving_mtx)
		return (0);
	while (i < data->map_height)
	{
		solving_mtx[i] = (int *)ft_calloc((data->map_width), sizeof(int));
		if (!solving_mtx)
			return (0);
		i++;
	}
	solving_mtx[i] = NULL;
	return (solving_mtx);
}

static int	**replace_for_solving_mtx(t_data *data, int i, int **solving_mtx)
{
	int	j;
	
	j = 0;
	while (j < data->map_width - 1)
	{
		if (data->map[i][j] == '1')
			solving_mtx[i][j] = 1;
		else if (data->map[i][j] == 'P')
			solving_mtx[i][j] = 2;
		else if (data->map[i][j] == 'C')
			solving_mtx[i][j] = -1;
		else if (data->map[i][j] == 'E')
			solving_mtx[i][j] = -2;
		else if (data->map[i][j] == '0')
			solving_mtx[i][j] = 0;
		j++;
	}
	return (solving_mtx);
}

int	**filling_solving_mtx(t_data *data)
{
	int	**solving_mtx;
	int	i;

	i = 0;
	solving_mtx = allocate_solving_mtx(data);
	while (solving_mtx[i] != NULL)
	{
		solving_mtx = replace_for_solving_mtx(data, i, solving_mtx);
		i++;
	}
	return (solving_mtx);
}