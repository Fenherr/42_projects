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

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	sign;
	long long	nbr;

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

long long	ft_get_time(void)
{
	struct timeval	time;
	long long		get_t;

	gettimeofday(&time, NULL);
	get_t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (get_t);
}

void	ft_sleep_smartly(t_data *data, long long time)
{
	long long	start;

	start = ft_get_time();
	while (!data->is_dead)
	{
		if (ft_get_time() - start >= time)
			break ;
		usleep(50);
	}
}

void	ft_actions_messages(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->writing);
	if (!data->is_dead)
		printf("%lli %i %s\n", ft_get_time() - data->starting_time, id, str);
	pthread_mutex_lock(&data->writing);
	return ;
}