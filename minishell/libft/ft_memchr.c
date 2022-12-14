/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:50:52 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 13:11:49 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (char)c)
			return ((void *)(&tmp[i]));
		i++;
	}
	return (NULL);
}
