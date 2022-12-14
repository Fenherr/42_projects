/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:14:25 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/03 16:03:09 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (in_set(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (in_set(set, s1[j]))
		j--;
	j++;
	if (j - i < 0)
		return (ft_strdup(""));
	return (ft_substr(s1, i, j - i));
}
