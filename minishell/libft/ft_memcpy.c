/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:22:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 13:11:38 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int				i;
	unsigned char	*tmp;
	unsigned char	*dst;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == NULL)
		dest = 0;
	i = 0;
	tmp = (unsigned char *) src;
	dst = (unsigned char *) dest;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		dst[i] = tmp[i];
		i++;
	}
	return ((void *) dst);
}
