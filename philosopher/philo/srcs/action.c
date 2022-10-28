/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:34:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:47:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_dead_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (FALSE);
}

int	ft_take_forks(t_philo *philo)
{
	if (philo->nb % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (!ft_dead_philo(philo))
		ft_message("has taken a fork", philo);
	if (ft_take_forks_utils(philo) == 1)
		return (1);
	return (0);
}

void	ft_eating(t_philo *philo)
{
	ft_message("is eating", philo);
	pthread_mutex_lock(&philo->data->mutex);
	philo->last_eat = ft_getting_time() - philo->data->starting_time;
	philo->time_to_die = philo->last_eat + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->data->mutex);
	ft_sleep(philo->data->time_to_eat, philo);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->nb_eat != -1)
		philo->nb_eat++;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleeping(t_philo *philo)
{
	ft_message("is sleeping", philo);
	ft_sleep(philo->data->time_to_sleep, philo);
}

void	ft_thinking(t_philo *philo)
{
	ft_message("is thinking", philo);
}