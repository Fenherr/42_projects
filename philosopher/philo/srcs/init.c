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

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_data) * data->nb_philo);
	if (!data->philo)
		return (ERROR);
	while (i < data->nb_philo)
	{
		data->philo[i].nb = i + 1;
		data->philo[i].eating = 0;
		data->philo[i].nb_eat = 0;
		data->philo[i].last_eat = 0;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].left_fork = &data->fork[i];
		data->philo[i].right_fork = &data->fork[(i + 1) % data->nb_philo];
		data->philo[i].data = data;
		i++;
	}
	return (SUCCESS);
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (ERROR);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex, NULL);
	return (SUCCESS);
}

int	ft_init(t_data *data, char **av)
{
	data->is_dead = 0;
	data->starting_time = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->eat_goal = ft_atoi(av[5]);
	else
		data->eat_goal = -1;
	if (init_mutex(data) == ERROR)
		return (ERROR);
	if (init_philo(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}