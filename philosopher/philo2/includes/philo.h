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
	int				left_fork;
	int				right_fork;
	long long		time_last_meal;
	struct s_data	*data;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				is_dead;
	int				ate_goal;
	long long		starting_time;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	*fork;
	pthread_mutex_t	writing;
	t_philo			*philo;
}	t_data;

/*Initialize function*/
void		ft_init(t_data *data, char **av);

/*Error functions*/
int			ft_nb_limits(char *str);
void		ft_error(int error);
void		error_message(char *str);

/*Utils functions*/
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
long long	ft_get_time(void);
void		ft_sleep_smartly(t_data *data, long long time);
void		ft_actions_messages(t_data *data, int id, char *str);

/*Patterns functions*/
int			ft_begin(t_data *data);

#endif