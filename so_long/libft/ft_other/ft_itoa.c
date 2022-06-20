/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:30:31 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:22:53 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_lenint(int n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		n = -n;
		j++;
	}
	while (n)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		j;
	int		i;

	i = n;
	j = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	j = ft_lenint(n);
	s = malloc(sizeof(char) * (j + 1));
	if (!s)
		return (NULL);
	if (n < 0)
		n = -n;
	s[j] = '\0';
	while (j--)
	{
		s[j] = n % 10 + '0';
		n = n / 10;
	}
	if (i < 0)
		s[0] = '-';
	return (s);
}
