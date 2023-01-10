/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:16:17 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:25:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putunbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putunbr(nb / 10);
		ft_putunbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
