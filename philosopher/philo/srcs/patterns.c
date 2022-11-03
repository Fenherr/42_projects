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
	if (data->nb_philo != 1)
	{
		pthread_mutex_lock(&(data->fork[philo->left_fork]));
		ft_actions_messages(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&(data->fork[philo->right_fork]));
		ft_actions_messages(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&(data->check_meal));
		ft_actions_messages(data, philo->id, "is eating");
		philo->time_meal = ft_get_time(data->start);
		pthread_mutex_unlock(&(data->check_meal));
		ft_sleep_smartly(data, data->time_to_eat);
		(philo->nb_ate)++;
		pthread_mutex_unlock(&(data->fork[philo->left_fork]));
		pthread_mutex_unlock(&(data->fork[philo->right_fork]));
	}
}

static void *ft_patterns(void *args)
{
	int		i;
	t_philo *philo;
	t_data 	*data;

	i = 0;
	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!data->is_dead && data->nb_philo != 1)
	{
		ft_eating(philo);
		if (data->ate_goal)
			break;
		ft_actions_messages(data, philo->id, "is sleeping");
		ft_sleep_smartly(data, data->time_to_sleep);
		ft_actions_messages(data, philo->id, "is thinking");
		i++;
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
		pthread_mutex_destroy(&(data->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->writing));
}

static void ft_check_if_is_dead(t_data *d, t_philo *p)
{
	int i;

	while (!(d->ate_goal))
	{
		i = 0;
		while (i < d->nb_philo && !d->is_dead)
		{
			pthread_mutex_lock(&(d->check_meal));
			if ((ft_get_time(d->start) - p[i].time_meal) > d->time_to_die)
			{
				ft_actions_messages(d, i, "died");
				d->is_dead = 1;
			}
			pthread_mutex_unlock(&(d->check_meal));
			usleep(100);
			i++;
		}
		if (d->is_dead)
			break ;
		i = 0;
		while (d->nb_eat != -1 && i < d->nb_philo && p[i].nb_ate >= d->nb_eat)
			i++;
		if (i == d->nb_philo)
			d->ate_goal = 1;
	}
}

void ft_begin(t_data *data)
{
	int 	i;
	t_philo *philo;

	i = 0;
	philo = data->philo;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, &ft_patterns, &philo[i]);
		philo[i].time_meal = ft_get_time(data->start);
		i++;
	}
	ft_check_if_is_dead(data, data->philo);
	ft_exit(data, philo);
}