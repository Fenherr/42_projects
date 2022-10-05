/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:34:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/05 13:36:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

void	ft_error_elm(t_data *data)
{
	if (data->exit > 1 || data->exit < 1)
		ft_error_msg("We need one and only one exit");
	if (data->player > 1 || data->player < 1)
		ft_error_msg("We need one and only one player");
	if (data->item < 1)
		ft_error_msg("We need at least 1 collectible");
}