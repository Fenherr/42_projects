/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:36:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/03 14:50:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	test(void)
{
	
}

void	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 600, 600, "So_long");
	data->exit = 0;
	data->item = 0;
	data->player = 0;
	//data->map = malloc(sizeof());
}