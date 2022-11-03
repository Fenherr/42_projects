/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 12:46:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_mutex(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (i >= 0)
	{
		pthread_mutex_init(&(data->writing), NULL);
		pthread_mutex_init(&(data->check_meal), NULL);
		pthread_mutex_init(&(data->fork[i]), NULL);
		i--;
	}
}

static void	init_philo(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].nb_ate = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].time_meal = 0;
		data->philo[i].data = data;
		i--;
	}
}

int	ft_init(t_data *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->ate_goal = 0;
	data->is_dead = 0;
	if (data->nb_philo < 1)
		return (2);
	if (data->nb_philo > 250 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (3);
	gettimeofday(&data->start, NULL);
	if (ac == 6 && ft_atoi(av[5]) > 0)
		data->nb_eat = ft_atoi(av[5]);
	else if (ac == 6 && ft_atoi(av[5]) < 1)
		return (3);
	else
		data->nb_eat = -1;
	init_mutex(data);
	init_philo(data);
	return (0);
}