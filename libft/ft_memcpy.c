/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:26:34 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/03/29 17:49:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_word;
	unsigned char	*src_word;

	i = 0;
	dest_word = (unsigned char *)dest;
	src_word = (unsigned char *)src;
	while (i < n)
	{
		*dest_word = *src_word;
		dest_word++;
		src_word++;
		i++;
	}
	return (dest);
}
