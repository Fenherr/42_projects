/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:34:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:47:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_getting_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_message(char *str, t_philo *philo)
{
	if (!ft_dead_philo(philo))
	{
		pthread_mutex_lock(&philo->data->mutex);
		printf("%d %d %s\n", ft_getting_time() - philo->data->starting_time,
			philo->nb, str);
		pthread_mutex_unlock(&philo->data->mutex);
	}
}

void	ft_sleep(int time, t_philo *philo)
{
	int	start;

	start = ft_getting_time();
	while ((ft_getting_time() - start) < time && !ft_dead_philo(philo))
		usleep(50);
}

int	ft_take_forks_utils(t_philo *philo)
{
	if (philo->nb % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		if (!ft_dead_philo(philo))
			ft_message("has taken a fork", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		if (!ft_dead_philo(philo))
			ft_message("has taken a fork", philo);
	}
	return (0);
}

void	ft_free(t_data *data)
{
	free(data->philo);
	free(data->fork);
}