/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:34:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/27 13:47:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define ERROR 0

typedef struct s_philo
{
	int				nb;
	int				eating;
	int				nb_eat;
	int				last_eat;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				is_dead;
	int				nb_philo;
	int				eat_goal;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				starting_time;
	struct timeval	time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo			*philo;
}	t_data;

/*Checking functions*/
int			ft_arg_are_digit(char **av);
int			ft_check_arg(int ac, char **av);
int			ft_arg_outside_limits(char **av);

/*Error functions*/
int			ft_error_args(void);
int			ft_error_syntax(void);
int			ft_error_limits(void);

/*Libft functions*/
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);

/*Init function*/
int			init(t_data *data, char **av);

#endif