/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:17 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:42:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_last_eat(t_philo *philo)
{
	if (ft_getting_time() - philo->data->starting_time > philo->time_to_die)
	{
		philo->data->is_dead = 1;
		printf("%d %d died\n", ft_getting_time() - philo->data->starting_time,
			philo->nb);
		return (ERROR);
	}
	else
		return (SUCCESS);
}

static int	check_if_philo_is_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (check_last_eat(&data->philo[i]) == ERROR)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	*ft_begin(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (check_if_philo_is_dead(data) == TRUE)
		{
			usleep(100);
			pthread_mutex_unlock(&data->mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_check_arg(ac, av))
	{
		if (ft_init(&data, av))
		{
			ft_begin_patterns(&data);
			ft_begin(&data);
			thread_join(&data);
			ft_free(&data);
		}
	}
}