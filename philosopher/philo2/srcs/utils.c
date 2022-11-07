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
	int				get_time;

	time.tv_sec = 0;
	gettimeofday(&time, NULL);
	t_sec = (time.tv_sec - start.tv_sec) * 1000;
	t_usec = (time.tv_usec - start.tv_usec) / 1000;
	get_time = t_sec + t_usec;
	return (get_time);
}

void	ft_print_message(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->writing);
	if (!data->is_dead)
		printf("%li %i %s\n", ft_get_time(data->start), id + 1, str);
	pthread_mutex_unlock(&data->writing);
	return ;
}

void	ft_smart_sleep(t_data *data, int time)
{
	int	start;

	start = ft_get_time(data->start);
	while (!data->is_dead)
	{
		if (ft_get_time(data->start) - start >= time)
			break ;
		usleep(50);
	}
}