/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 13:11:32 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*s;

	dst = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
		return ((void *)dst);
	}
	while (i < n)
	{
		dst[n - i - 1] = s[n - i - 1];
		i++;
	}
	return ((void *)dst);
}
