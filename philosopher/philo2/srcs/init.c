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

static int	init_mutex(t_data *data)
{
	int	i;

	i = data->nb_philo;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (ERROR);
	while (i >= 0)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (SUCCESS);
		i--;
	}
	if (pthread_mutex_init(&data->writing, NULL))
		return (SUCCESS);
	if (pthread_mutex_init(&data->check_meal, NULL))
		return (SUCCESS);
	return (ERROR);
}

static int	init_philo(t_data *data)
{
	int	i;

	i = data->nb_philo;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	while (i >= 0)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_ate = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].time_last_meal = 0;
		data->philo[i].data = data;
	}
	return (ERROR);
}

void	ft_init(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->ate_goal = 0;
	data->is_dead = 0;
	if (ft_nb_limits(av[5]) || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->nb_philo < 1)
		ft_error(1);
	if (av[5])
	{
		data->nb_eat = ft_atoi(av[5]);
		if (data->nb_eat < 1)
			ft_error(1);
	}
	else
		data->nb_eat = -1;
	if (init_mutex(data))
		ft_error(2);
	init_philo(data);
}