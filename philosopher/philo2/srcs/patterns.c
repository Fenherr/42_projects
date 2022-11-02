/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/11/02 21:43:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void ft_eating(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->left_fork]));
	ft_actions_messages(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->fork[philo->right_fork]));
	ft_actions_messages(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->check_meal));
	ft_actions_messages(data, philo->id, "is eating");
	philo->time_last_meal = ft_get_time();
	pthread_mutex_unlock(&(data->check_meal));
	ft_sleep_smartly(data, data->time_to_eat);
	philo->nb_ate++;
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork]));
}

static void *ft_patterns(void *args)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!data->is_dead)
	{
		ft_eating(philo);
		if (data->ate_goal)
			break;
		ft_actions_messages(data, philo->id, "is sleeping");
		ft_sleep_smartly(data, data->time_to_sleep);
		ft_actions_messages(data, philo->id, "is thinking");
	}
	return (NULL);
}

static void ft_exit(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->writing);
}

static void ft_check_if_is_dead(t_data *data, t_philo *philo)
{
	int i;

	while (!data->ate_goal)
	{
		i = 0;
		while (i < data->nb_philo && !data->is_dead)
		{
			pthread_mutex_lock(&data->check_meal);
			if ((philo[i].time_last_meal - ft_get_time()) > data->time_to_die)
			{
				ft_actions_messages(data, i, "died");
				data->is_dead = 1;
			}
			pthread_mutex_unlock(&data->check_meal);
			usleep(100);
			i++;
		}
		if (data->is_dead)
			break;
		i = 0;
		while (data->nb_eat != -1 && i < data->nb_philo && philo[i].nb_ate >= data->nb_eat)
			i++;
		if (i == data->nb_philo)
			data->ate_goal = 1;
	}
}

int ft_begin(t_data *data)
{
	int i;
	t_philo *philo;

	i = 0;
	philo = data->philo;
	data->starting_time = ft_get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &ft_patterns, &philo[i]))
			return (1);
		philo[i].time_last_meal = ft_get_time();
		i++;
	}
	ft_check_if_is_dead(data, data->philo);
	ft_exit(data, philo);
	return (0);
}