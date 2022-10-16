/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:20:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/16 14:06:15 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_search_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height - 1)
	{
		j = 0;
		while (data->map[i][j] != 'P' && j < data->map_length - 1)
			j++;
		if (data->map[i][j] == 'P')
		{
			data->player.x = i;
			data->player.y = j;
		}
		i++;
	}
}