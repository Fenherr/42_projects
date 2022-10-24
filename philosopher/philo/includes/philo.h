/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:34:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/24 15:50:01 by ngrenoux         ###   ########.fr       */
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

typedef struct s_data
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	long int		time_to_eat;
	long int		time_to_die;
	long int		time_to_sleep;
	int				nb_philo;
	int				nb_philo_eat;
}	t_data;

void	ft_init(t_data *data);

#endif