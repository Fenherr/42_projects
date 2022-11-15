/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/11/02 21:43:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_patterns_utils(t_data *data, t_philo *philo)
{
	int		end;
	int		meal;

	pthread_mutex_lock(&data->reaper);
	end = data->is_dead;
	pthread_mutex_unlock(&data->reaper);
	pthread_mutex_lock(&data->check_meal);
	meal = data->all_eat;
	pthread_mutex_unlock(&data->check_meal);
	while (!end && data->nb_philo != 1)
	{
		ft_eating(philo);
		if (meal)
			break ;
		ft_actions_messages(data, philo->id, "is sleeping");
		ft_sleep_smartly(data, data->time_to_sleep);
		ft_actions_messages(data, philo->id, "is thinking");
		pthread_mutex_lock(&data->reaper);
		end = data->is_dead;
		pthread_mutex_unlock(&data->reaper);
	}
}

void	ft_check_death_utils(t_data *d, t_philo *p)
{
	int	i;

	i = 0;
	while (i < d->nb_philo && !d->is_dead)
	{
		pthread_mutex_lock(&d->check_meal);
		if ((ft_get_time(d->start) - p[i].meal_time) > d->time_to_die)
		{
			ft_actions_messages(d, i, "died");
			pthread_mutex_lock(&d->reaper);
			d->is_dead = 1;
			pthread_mutex_unlock(&d->reaper);
		}
		pthread_mutex_unlock(&d->check_meal);
		usleep(100);
		i++;
	}
}
