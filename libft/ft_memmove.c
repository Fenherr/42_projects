/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:40:21 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/03/31 09:23:59 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_word;
	unsigned char	*src_word;
	size_t			i;

	i = 0;
	dest_word = (unsigned char *)dest;
	src_word = (unsigned char *)src;
	if (dest > src)
	{
		while (n-- > 0)
			dest_word[n] = src_word[n];
	}
	else
	{
		while (i < n)
		{
			dest_word[i] = src_word[i];
			i++;
		}
	}
	return (dest);
}
