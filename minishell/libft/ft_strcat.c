/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:33:27 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 13:37:03 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	lendst;
	int	lensrc;

	if (dst == NULL)
		return (0);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	while (src[i] != '\0')
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
