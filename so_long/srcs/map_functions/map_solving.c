/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:08 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/16 14:43:03 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_safe(t_data *data, int **solving_tab, int x, int y)
{
	if (x >= 0 && x < data->map_height - 1 && y >= 0
		&&	y < data->map_length - 1 && solving_tab[x][y] == 2)
		return (1);
	return (0);
}

static int	solve(t_data *data, int **solve_tab, int x, int y, int **null_tab)
{	
	if (solve_tab[x][y] == -2)
	{
		null_tab[x][y] = 1;
		return (1);
	}
	if (is_safe(data, solve_tab, x, y) == 1)
	{
		if (null_tab[x][y] == 1)
			return (0);
		null_tab[x][y] = 1;
		if (solve(data, solve_tab, x + 1, y, null_tab) == 1)
			return (1);
		if (solve(data, solve_tab, x, y + 1, null_tab) == 1)
			return (1);
		null_tab[x][y] = 0;
		return (0);
	}
	return (0);
}

int	solve_map(t_data *data)
{
	int	**null_tab;
	int	**solve_tab;

	solve_tab = filling_solving_tab(data);
	null_tab = filling_null_tab(data);
	if (solve(data, solve_tab, data->player.x, data->player.y, null_tab) == 0)
		ft_error_msg("Impossible to solve the game", data->map_path,
			data->map);
	return (1);
}