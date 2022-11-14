/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 12:46:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	ft_get_time(struct timeval start)
{
	struct timeval	time;
	int				t_sec;
	int				t_usec;

	time.tv_sec = 0;
	gettimeofday(&time, NULL);
	t_sec = (time.tv_sec - start.tv_sec) * 1000;
	t_usec = (time.tv_usec - start.tv_usec) / 1000;
	return (t_sec + t_usec);
}

void	ft_sleep_smartly(t_data *data, long long time)
{
	long long	start;
	int			end;

	pthread_mutex_lock(&data->reaper);
	end = data->is_dead;
	pthread_mutex_unlock(&data->reaper);
	start = ft_get_time(data->start);
	while (!end)
	{
		if (ft_get_time(data->start) - start >= time)
			break ;
		usleep(50);
	}
}

void	ft_actions_messages(t_data *data, int id, char *str)
{
	int	end;

	pthread_mutex_lock(&data->reaper);
	end = data->is_dead;
	pthread_mutex_unlock(&data->reaper);
	pthread_mutex_lock(&(data->writing));
	if (!end)
	{
		printf("%li ", ft_get_time(data->start));
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(data->writing));
	return ;
}

void	ft_check_all_eat(t_data *data, t_philo *philo)
{
	int	i;
	int	ate_count;

	i = 0;
	pthread_mutex_lock(&data->check_meal);
	ate_count = philo[i].nb_ate;
	pthread_mutex_unlock(&data->check_meal);
	while (data->meal_goal != -1 && i < data->nb_philo
		&& ate_count >= data->meal_goal)
	{
		i++;
		pthread_mutex_lock(&data->check_meal);
		ate_count = philo[i].nb_ate;
		pthread_mutex_unlock(&data->check_meal);
	}
	if (i == data->nb_philo)
		data->all_eat = 1;
}
