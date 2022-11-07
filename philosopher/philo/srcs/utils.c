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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] <= '\r' && nptr[i] >= '\t'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * sign);
}

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

	start = ft_get_time(data->start);
	while (!data->is_dead)
	{
		if (ft_get_time(data->start) - start >= time)
			break ;
		usleep(50);
	}
}

void	ft_actions_messages(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing));
	if (!data->is_dead)
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

	i = 0;
	while (data->meal_goal != -1 && i < data->nb_philo
		&& philo[i].nb_ate >= data->meal_goal)
		i++;
	if (i == data->nb_philo)
		data->all_eat = 1;
}
