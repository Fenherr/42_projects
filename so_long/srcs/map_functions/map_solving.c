/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:08 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/18 16:04:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_side(t_maze_solver *maze)
{
	if (maze->solve_mtx[maze->x - 1][maze->y] == 0)
		maze->solve_mtx[maze->x - 1][maze->y] = maze->start + 1;
	if (maze->solve_mtx[maze->x + 1][maze->y] == 0)
		maze->solve_mtx[maze->x + 1][maze->y] = maze->start + 1;
	if (maze->solve_mtx[maze->x][maze->y - 1] == 0)
		maze->solve_mtx[maze->x][maze->y - 1] = maze->start + 1;
	if (maze->solve_mtx[maze->x][maze->y + 1] == 0)
		maze->solve_mtx[maze->x][maze->y + 1] = maze->start + 1;
}

static int	check_item(t_maze_solver *maze)
{
	if (maze->solve_mtx[maze->x - 1][maze->y] == -1)
	{
		maze->solve_mtx[maze->x - 1][maze->y] = maze->start + 1;
		maze->count_item++;
	}
	if (maze->solve_mtx[maze->x + 1][maze->y] == -1)
	{
		maze->solve_mtx[maze->x + 1][maze->y] = maze->start + 1;
		maze->count_item++;
	}
	if (maze->solve_mtx[maze->x][maze->y - 1] == -1)
	{
		maze->solve_mtx[maze->x][maze->y - 1] = maze->start + 1;
		maze->count_item++;
	}
	if (maze->solve_mtx[maze->x][maze->y + 1] == -1)
	{
		maze->solve_mtx[maze->x][maze->y + 1] = maze->start + 1;
		maze->count_item++;
	}
	return (maze->count_item);
}

static int	check_exit(t_maze_solver *maze)
{
	if (maze->solve_mtx[maze->x - 1][maze->y] == -2)
		return (1);
	if (maze->solve_mtx[maze->x + 1][maze->y] == -2)
		return (1);
	if (maze->solve_mtx[maze->x][maze->y - 1] == -2)
		return (1);
	if (maze->solve_mtx[maze->x][maze->y + 1] == -2)
		return (1);
	return (0);
}

static int	check_solve(t_maze_solver *maze, t_data *data)
{
	maze->x = 0;
	while (maze->x < data->map_height)
	{
		maze->y = 0;
		while (maze->y < data->map_width)
		{
			if (maze->solve_mtx[maze->x][maze->y] == maze->start)
			{
				check_side(maze);
				maze->count_item = check_item(maze);
				if (maze->end == 0)
					maze->end = check_exit(maze);
			}
			maze->y++;
		}
		maze->x++;
	}
	if (maze->end == 1 && maze->count_item == data->nb_item)
		return (1);
	return (0);
}

int	solve_map(t_data *data)
{
	t_maze_solver	maze;

	maze.solve_mtx = filling_solving_mtx(data);
	maze.start = 2;
	maze.end = 0;
	maze.count_item = 0;
	while (maze.start < (data->map_height * data->map_width))
	{
		if (check_solve(&maze, data) == 1)
		{
			ft_free_mtx(maze.solve_mtx);
			return (1);
		}
		maze.start++;
	}
	ft_free_mtx(maze.solve_mtx);
	return (0);
}
