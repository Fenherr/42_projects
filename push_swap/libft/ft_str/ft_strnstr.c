/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:52:34 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:11:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*c;
	size_t	i;
	size_t	j;

	i = 0;
	str = (char *)big;
	c = (char *)little;
	if (c[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (i + j < len && str [i + j] == c[j])
		{
			if (c[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
