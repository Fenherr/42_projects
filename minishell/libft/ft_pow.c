/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:55:26 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 10:11:19 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	if (power > 0)
	{
		power --;
		res = nb * ft_pow(nb, power);
	}
	return (res);
}
