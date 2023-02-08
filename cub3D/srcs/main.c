/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:16:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/02 18:16:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error_msg("We only need the map path.", NULL, NULL);
	ft_init(&data, av[1]);
	ft_parsing(&data);
	ft_free_all(&data);
	ft_free_array(data.map);
}
