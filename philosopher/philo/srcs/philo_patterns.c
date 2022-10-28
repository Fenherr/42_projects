/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:17 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:42:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_patterns(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (philo->data->is_dead == 0)
	{
		if (ft_dead_philo(philo))
			return (0);
		ft_take_forks(philo);
		if (ft_dead_philo(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		ft_eating(philo);
		if (ft_dead_philo(philo))
			return (0);
		ft_sleeping(philo);
		if (ft_dead_philo(philo))
			return (0);
		ft_thinking(philo);
	}
	return (0);
}

void	thread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

void	ft_begin_patterns(t_data *data)
{
	int	i;

	i = 0;
	data->starting_time = ft_getting_time();
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, &philo_patterns,
			(void *)&data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}