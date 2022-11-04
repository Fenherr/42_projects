#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define ERROR 0

typedef struct s_philo
{
	int				id;
	int				nb_ate;
	int				l_fork;
	int				r_fork;
	long long		meal_time;
	struct s_data	*data;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_goal;
	int				is_dead;
	int				all_eat;
	struct timeval	start;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	writing;
	pthread_mutex_t	reaper;
	t_philo			philo[250];
}	t_data;

/*Init function*/
int		ft_init(t_data *data, int ac, char **av);

/*Error function*/
void	ft_error(int nb_error);

/*Utils functions*/
int		ft_atoi(const char *nptr);
int		ft_get_time(struct timeval start);
void	ft_print_message(t_data *data, int id, char *str);
void	ft_smart_sleep(t_data *data, int time);

/*Patterns function*/
void	ft_begin(t_data *data);

/*Check death function*/
void	ft_check_if_is_dead(t_data *data);

#endif