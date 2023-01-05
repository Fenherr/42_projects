/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:16:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/01/05 13:52:04 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_exit(t_data *data)
{
	ft_free(data);
	return (0);
}

static int	ft_key_managment(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_exit(data);
	return (0);
}

static void	ft_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_managment, data);
	mlx_hook(data->win, 17, 1L >> 2, ft_exit, data);
 	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_init(&data, av[1]);
		ft_parsing(&data);
		ft_window(&data);
	}
	return (0);
}
