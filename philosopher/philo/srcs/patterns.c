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

static void	ft_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->nb_philo != 1)
	{
		pthread_mutex_lock(&data->fork[philo->l_fork]);
		ft_actions_messages(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&data->fork[philo->r_fork]);
		ft_actions_messages(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&data->check_meal);
		ft_actions_messages(data, philo->id, "is eating");
		philo->meal_time = ft_get_time(data->start);
		pthread_mutex_unlock(&data->check_meal);
		ft_sleep_smartly(data, data->time_to_eat);
		philo->nb_ate++;
		pthread_mutex_unlock(&data->fork[philo->l_fork]);
		pthread_mutex_unlock(&data->fork[philo->r_fork]);
	}
}

static void	*ft_patterns(void *args)
{
	t_philo	*philo;
	t_data	*data;
	int		end;

	philo = (t_philo *)args;
	data = philo->data;
	pthread_mutex_lock(&data->reaper);
	end = data->is_dead;
	pthread_mutex_unlock(&data->reaper);
	if (philo->id % 2)
		usleep(15000);
	while (!end && data->nb_philo != 1)
	{
		ft_eating(philo);
		if (data->all_eat)
			break ;
		ft_actions_messages(data, philo->id, "is sleeping");
		ft_sleep_smartly(data, data->time_to_sleep);
		ft_actions_messages(data, philo->id, "is thinking");
		pthread_mutex_lock(&data->reaper);
		end = data->is_dead;
		pthread_mutex_unlock(&data->reaper);
	}
	return (NULL);
}

static void	ft_exit(t_data *data, t_philo *philo)
{
	int	i;

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

static void	ft_check_if_is_dead(t_data *d, t_philo *p)
{
	int	i;

	while (!d->all_eat)
	{
		i = -1;
		while (++i < d->nb_philo && !d->is_dead)
		{
			pthread_mutex_lock(&d->reaper);
			if ((ft_get_time(d->start) - p[i].meal_time) > d->time_to_die)
			{
				ft_actions_messages(d, i, "died");
				d->is_dead = 1;
			}
			pthread_mutex_unlock(&d->reaper);
			usleep(100);
		}
		pthread_mutex_lock(&d->reaper);
		if (d->is_dead)
		{
			pthread_mutex_unlock(&d->reaper);
			break ;
		}
		pthread_mutex_unlock(&d->reaper);
		ft_check_all_eat(d, p);
	}
}

void	ft_begin(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, &ft_patterns, &philo[i]);
		philo[i].meal_time = ft_get_time(data->start);
		i++;
	}
	ft_check_if_is_dead(data, data->philo);
	ft_exit(data, philo);
}
