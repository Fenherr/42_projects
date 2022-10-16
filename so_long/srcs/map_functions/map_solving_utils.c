/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/16 13:47:13 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	**allocate_solving_tab(t_data *data)
{
	int	i;
	int	**solving_tab;

	i = 0;
	solving_tab = (int **)ft_calloc((data->map_height + 1), sizeof(int *));
	if (!solving_tab)
		return (0);
	while (i < data->map_height)
	{
		solving_tab[i] = (int *)ft_calloc((data->map_length), sizeof(int));
		if (!solving_tab)
			return (0);
		i++;
	}
	solving_tab[i] = NULL;
	return (solving_tab);
}

static int	**replace_for_solving_tab(t_data *data, int i, int **solving_tab)
{
	int	j;
	
	j = 0;
	while (j < data->map_length - 1)
	{
		if (data->map[i][j] == '1')
			solving_tab[i][j] = 1;
		else if (data->map[i][j] == 'P')
			solving_tab[i][j] = 2;
		else if (data->map[i][j] == 'C')
			solving_tab[i][j] = -1;
		else if (data->map[i][j] == 'E')
			solving_tab[i][j] = -2;
		else if (data->map[i][j] == '0')
			solving_tab[i][j] = 0;
		j++;
	}
	return (solving_tab);
}

int	**filling_solving_tab(t_data *data)
{
	int	**solving_tab;
	int	i;

	i = 0;
	solving_tab = allocate_solving_tab(data);
	while (solving_tab[i] != NULL)
	{
		solving_tab = replace_for_solving_tab(data, i, solving_tab);
		i++;
	}
	return (solving_tab);
}

int	**filling_null_tab(t_data *data)
{
	int	**tmp_null_tab;

	tmp_null_tab = allocate_solving_tab(data);
	return (tmp_null_tab);
}