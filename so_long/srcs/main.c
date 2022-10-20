/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/20 11:15:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_win(t_data *data)
{
	int	i;
	int	j;

	ft_search_exit_pos(data);
	if (data->nb_item == 0)
	{
		mlx_destroy_image(data->mlx, data->exit.img.img);
		data->exit.img.img = mlx_xpm_file_to_image(data->mlx,
				"resources/tiles/door_open.xpm", &i, &j);
		mlx_put_image_to_window(data->mlx, data->win, data->exit.img.img,
			data->exit.x * 64, data->exit.y * 64);
	}
}

int	keys_management(int keycode, t_data *data)
{
	ft_search_player_pos(data);
	if (keycode == XK_Escape)
		ft_exit(data);
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		ft_up_move(data);
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		ft_down_move(data);
	if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		ft_left_move(data);
	if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		ft_right_move(data);
	check_if_win(data);
	if (data->map[data->player.y][data->player.x] == 'E')
		ft_exit_if_win(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_init(&data, av[1]);
	ft_map_parsing(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (data.map_width - 1) * 64,
			data.map_height * 64, "So_long");
	place_img_in_game(&data);
	ft_graphics(&data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, ft_exit, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &keys_management, &data);
	mlx_loop(data.mlx);
}
