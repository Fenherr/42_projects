/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:40:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/22 15:18:14 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_puthexa(unsigned int nb, const char form)
{
	printf("%x", nb);
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, form);
		ft_puthexa(nb % 16, form);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((nb - 10 + 97), form);
			if (form == 'X')
				ft_putchar_fd((nb - 10 + 65), form);
		}
	}
}

int	ft_printhexa(unsigned int nb, const char form)
{
	printf("%d", nb);
	if (nb == 0)
		return (write(1, "0", 1));
	else if (nb < 0)
	{
		nb *= -1;
		ft_puthexa(nb, form);
		printf("%d", nb);
	}
	else
		ft_puthexa(nb, form);
	return (ft_len_hexa(nb));
}

int	main()
{
	ft_printhexa(-1, 'x');
	return (0);
}
