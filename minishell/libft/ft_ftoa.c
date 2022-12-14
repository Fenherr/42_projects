/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:37:03 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/16 10:44:48 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float nb)
{
	int		intpart;
	float	decpart;
	char	*res;
	char	*tmp;

	intpart = nb;
	decpart = nb - (double)intpart;
	decpart *= 1000000.0;
	if (decpart < 0.0)
		decpart *= -1.0;
	res = ft_itoa(intpart);
	tmp = ft_itoa((int)decpart);
	res = ft_strjoin_free_1st_p(res, ".");
	res = ft_strjoin_free_1st_p(res, tmp);
	free(tmp);
	return (res);
}
