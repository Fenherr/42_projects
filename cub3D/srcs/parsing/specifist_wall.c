/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifist_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:02:51 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/08 14:42:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_check_spec_high_len(t_data *d, int i, int j)
{
	if (j < (int)ft_strlen(d->dup_map[i - 1])
		|| j < (int)ft_strlen(d->dup_map[i + 1]))
	{
		if (d->dup_map[i - 1][j] == '0' && d->dup_map[i + 1][j] == '0'
			&& d->dup_map[i][j - 1] != '0' && d->dup_map[i][j + 1] != '0')
			d->dup_map[i][j] = '8';
		if (d->dup_map[i][j - 1] == '0' && d->dup_map[i][j + 1] == '0'
			&& d->dup_map[i - 1][j] != '0' && d->dup_map[i + 1][j] != '0')
			d->dup_map[i][j] = '9';
	}
}

static void	ft_check_spec(t_data *d, int i, int j)
{
	if (d->dup_map[i - 1][j] == '0' && d->dup_map[i + 1][j] == '0'
		&& d->dup_map[i][j - 1] != '0' && d->dup_map[i][j + 1] != '0')
		d->dup_map[i][j] = '8';
	if (d->dup_map[i][j - 1] == '0' && d->dup_map[i][j + 1] == '0'
		&& d->dup_map[i - 1][j] != '0' && d->dup_map[i + 1][j] != '0')
		d->dup_map[i][j] = '9';
}

void	ft_check_spec_wall(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (data->dup_map[i])
	{
		j = 1;
		len = ft_strlen(data->dup_map[i]);
		while (data->dup_map[i][j] && i < data->map_height - 1)
		{
			if (data->dup_map[i][j] == '5' && j < len - 2)
			{
				if (len > (int)ft_strlen(data->dup_map[i + 1])
					|| len > (int)ft_strlen(data->dup_map[i - 1]))
					ft_check_spec_high_len(data, i, j);
				else
					ft_check_spec(data, i, j);
			}
			j++;
		}
		i++;
	}
}
