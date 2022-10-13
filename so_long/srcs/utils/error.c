/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:34:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/12 10:22:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error_msg(char *str, char *free_str, char **free_arr)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	ft_free(free_str, free_arr);
	exit(0);
}

void	ft_error_elm(t_data *data)
{
	if (data->nb_exit > 1 || data->nb_exit < 1)
		ft_error_msg("We need one and only one exit", NULL, NULL);
	if (data->nb_player > 1 || data->nb_player < 1)
		ft_error_msg("We need one and only one player", NULL, NULL);
	if (data->nb_item < 1)
		ft_error_msg("We need at least 1 collectible", NULL, NULL);
}