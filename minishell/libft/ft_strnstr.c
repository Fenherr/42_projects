/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:19:55 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 13:10:47 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;

	if (big == NULL && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j <= len)
			j++;
		if (little[j] == '\0' && i + j != len + 1)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
