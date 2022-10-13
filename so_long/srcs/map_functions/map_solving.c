/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:08 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/13 14:11:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	solve_map(t_data *data)
{
	int	**solving_tab;
	int	i;
	int	j;

	i = 0;
	solving_tab = filling_solving_tab(data);
	while (i < data->map_height - 1)
	{
		j = 0;
		while (j < data->map_length - 1)
		{
			ft_printf("%d ", solving_tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}