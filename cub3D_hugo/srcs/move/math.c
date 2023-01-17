/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:44:21 by hde-min           #+#    #+#             */
/*   Updated: 2022/12/27 13:44:21 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

double	ft_radiant(double angle)
{
	double	radiant;

	radiant = angle * 0.0174533;
	return (radiant);
}

double	ft_clock(double angle)
{
	angle *= 30;
	while (angle >= 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	return (angle);
}

int	ft_round(double to_round)
{
	int	r;

	r = (int)to_round;
	return (r);
}
