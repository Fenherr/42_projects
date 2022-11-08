/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:05:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 12:46:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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
	pthread_mutex_t	check_meal;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	writing;
	pthread_mutex_t	reaper;
	t_philo			philo[250];
}	t_data;

/*Initialize function*/
int			ft_init(t_data *data, int ac, char **av);

/*Error functions*/
void		ft_error(int error);
void		error_message(char *str);

/*Utils functions*/
int			ft_atoi(const char *nptr);
long int	ft_get_time(struct timeval starting_time);
void		ft_sleep_smartly(t_data *data, long long time);
void		ft_actions_messages(t_data *data, int id, char *str);
void		ft_check_all_eat(t_data *data, t_philo *philo);
int			ft_arg_are_num(char **av);

/*Patterns functions*/
void		ft_begin(t_data *data);

#endif