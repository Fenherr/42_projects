#include "../includes/philo.h"

int	are_you_dead(t_data *data, t_philo philo)
{
	if (ft_get_time(data->start) - philo.meal_time > data->time_to_die)
	{
		pthread_mutex_lock(&data->reaper);
		data->is_dead = 1;
		ft_print_message(data, philo.id, "died");
		pthread_mutex_unlock(&data->reaper);
		return (TRUE);
	}
	else
		return (FALSE);
}

int	the_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (are_you_dead(data, data->philo[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	ft_check_if_is_dead(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (!data->all_eat)
	{
		pthread_mutex_lock(&data->meal_check);
		if (the_end(data) == TRUE)
		{
			usleep(100);
			pthread_mutex_unlock(&data->meal_check);
			return ;
		}
		pthread_mutex_unlock(&data->meal_check);
		pthread_mutex_lock(&data->reaper);
		if (data->is_dead)
			break ;
		pthread_mutex_unlock(&data->reaper);
		while (data->meal_goal != -1 && i < data->nb_philo
			&& philo[i].nb_ate >= data->meal_goal)
			i++;
		if (i == data->nb_philo)
			data->all_eat = 1;
	}
}