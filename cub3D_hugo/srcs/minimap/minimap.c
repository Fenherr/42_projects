/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:25:54 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/10 13:00:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_put_cube(t_data *data, int x, int y, int color)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (j < 40)
	{
		while (k < 40)
		{
			data->minimap[(((j + (y * 40)) * 360) + k) + (x * 40)] = color;
			k++;
		}
		k = 0;
		j++;
	}
}

void	ft_witch_cube(t_data *data, t_minimap *mini)
{
	if (mini->x < 0 || mini->y < 0)
		ft_put_cube(data, mini->i, mini->j, 0x7F7F7F);
	else if (data->map[mini->y] == NULL)
		ft_put_cube(data, mini->i, mini->j, 0x7F7F7F);
	else if (!data->map[mini->y][mini->x])
		ft_put_cube(data, mini->i, mini->j, 0x7F7F7F);
	else if (data->map[mini->y][mini->x] == ' ')
		ft_put_cube(data, mini->i, mini->j, 0x7F7F7F);
	else if (data->map[mini->y][mini->x] == '1')
		ft_put_cube(data, mini->i, mini->j, 0x000000);
	else if (data->map[mini->y][mini->x] == '0'
		|| ft_isalpha(data->map[mini->y][mini->x]))
		ft_put_cube(data, mini->i, mini->j, 0xFFFFFF);
	else if (mini->x == ft_round(data->x_p)
		&& mini->y == ft_round(data->y_p))
		ft_put_cube(data, mini->i, mini->j, 0x7F00FF);
	else
		ft_put_cube(data, mini->i, mini->j, 0x7F7F7F);
	return ;
}

void	ft_put_minimap_pixel(t_data *data)
{
	t_minimap	mini;

	mini.i = 0;
	mini.j = 0;
	mini.x = ft_round(data->x_p);
	mini.y = ft_round(data->y_p);
	mini.x = mini.x - 4;
	mini.y = mini.y - 2;
	while (mini.y < ft_round(data->y_p) + 3)
	{
		while (mini.x < ft_round(data->x_p) + 5)
		{
			ft_witch_cube(data, &mini);
			mini.i++;
			mini.x++;
		}
		mini.i = 0;
		mini.x = ft_round(data->x_p) - 4;
		mini.y++;
		mini.j++;
	}
	ft_put_cube(data, 4, 2, 0x7F00FF);
}

void	ft_minimap(t_data *data)
{
	ft_put_minimap_pixel(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image[3].img,
		0, (WIN_HEIGHT - (200)));
}
