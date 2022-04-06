/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:48:51 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/04 13:59:35 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_forbiddenchar(char c, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (set[i])
	{
		if (set[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_forbiddenchar(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	while (ft_forbiddenchar(s1[j], set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
