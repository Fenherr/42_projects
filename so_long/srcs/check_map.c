/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:24:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/04 16:07:36 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static size_t	len_line(t_data data)
{
	char	*line;
	size_t	len;
	int		fd;
	
	len = 0;
	fd = open(data.map_name, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	close (fd);
	return (len);
}

void	ft_check_len_map(t_data data)
{
	int		fd;
	size_t	len;
	char	*line;

	fd = open(data.map_name, O_RDONLY);
	len = len_line(data);
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) != len)
		{
			ft_putstr_fd("Error\nWrong map length\n", 2);
			exit(0);
		}
	}
	close (fd);
}