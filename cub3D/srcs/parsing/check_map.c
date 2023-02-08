/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:42:50 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/07 15:28:12 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_check_invalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0'
			&& !ft_is_player(str[i]) && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_map(t_data *data, int fd)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] == '\n')
		{
			close (fd);
			ft_free_all(data);
			ft_error_msg("Empty line detected.", NULL, data->map);
		}
		if (ft_check_invalid_char(data->map[i]))
		{
			close (fd);
			ft_free_all(data);
			ft_error_msg("Invalid character detected.", NULL, data->map);
		}
		i++;
	}
}
