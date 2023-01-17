/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:34:44 by hde-min           #+#    #+#             */
/*   Updated: 2023/01/17 12:31:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_better_round(double to_round)
{
	int	r;

	to_round = to_round + 0.5;
	r = (int)to_round;
	return (r);
}

double	ft_lmove_x(double angle)
{
	double	x;

	angle -= 3;
	if (angle < 0)
		angle += 12;
	angle = ft_clock(angle);
	angle = ft_radiant(angle);
	x = (cos(angle) * 0.1);
	return (x);
}

double	ft_lmove_y(double angle)
{
	double	y;

	angle -= 3;
	if (angle < 0)
		angle += 12;
	angle = ft_clock(angle);
	angle = ft_radiant(angle);
	y = (sin(angle) * 0.1);
	return (y);
}
