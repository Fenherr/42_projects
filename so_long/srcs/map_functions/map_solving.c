/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:08 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/17 16:07:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int solve_map(t_data *data)
{
	t_maze_solver maze;

	maze.solve_mtx = filling_solving_mtx(data);
	maze.start = 2;
	maze.count_item = 0;
	while (maze.start < (data->map_height * data->map_width))
	{
		maze.x = 0;
		while (maze.x < data->map_height)
		{
			maze.y = 0;
			while (maze.y < data->map_width)
			{
				if (maze.solve_mtx[maze.x][maze.y] == maze.start)
				{
					if (maze.solve_mtx[maze.x - 1][maze.y] == 0)
						maze.solve_mtx[maze.x - 1][maze.y] = maze.start + 1;
					if (maze.solve_mtx[maze.x + 1][maze.y] == 0)
						maze.solve_mtx[maze.x + 1][maze.y] = maze.start + 1;
					if (maze.solve_mtx[maze.x][maze.y - 1] == 0)
						maze.solve_mtx[maze.x][maze.y - 1] = maze.start + 1;
					if (maze.solve_mtx[maze.x][maze.y + 1] == 0)
						maze.solve_mtx[maze.x][maze.y + 1] = maze.start + 1;
					if (maze.solve_mtx[maze.x - 1][maze.y] == -1)
					{
						maze.solve_mtx[maze.x - 1][maze.y] = maze.start + 1;
						maze.count_item++;
					}
					if (maze.solve_mtx[maze.x + 1][maze.y] == -1)
					{
						maze.solve_mtx[maze.x + 1][maze.y] = maze.start + 1;
						maze.count_item++;
					}
					if (maze.solve_mtx[maze.x][maze.y - 1] == -1)
					{
						maze.solve_mtx[maze.x][maze.y - 1] = maze.start + 1;
						maze.count_item++;
					}
					if (maze.solve_mtx[maze.x][maze.y + 1] == -1)
					{
						maze.solve_mtx[maze.x][maze.y + 1] = maze.start + 1;
						maze.count_item++;
					}
					if (maze.solve_mtx[maze.x - 1][maze.y] == -2
						&& maze.count_item == data->nb_item)
						return (1);
					if (maze.solve_mtx[maze.x + 1][maze.y] == -2
						&& maze.count_item == data->nb_item)
						return (1);
					if (maze.solve_mtx[maze.x][maze.y - 1] == -2
						&& maze.count_item == data->nb_item)
						return (1);
					if (maze.solve_mtx[maze.x][maze.y + 1] == -2
						&& maze.count_item == data->nb_item)
						return (1);
				}
				maze.y++;
			}
			maze.x++;
		}
		maze.start++;
	}
	return (0);
}