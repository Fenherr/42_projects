/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:15:53 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/24 12:11:08 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double nb)
{
	double	tmp;
	double	res;

	if (nb <= 0.0)
		return (0.0);
	tmp = 0.0;
	res = nb / 2.0;
	while (res != tmp)
	{
		tmp = res;
		res = (nb / tmp + tmp) / 2;
	}
	return (res);
}
