/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuperjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:02:17 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/21 11:49:42 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_after_i(char *res, char *sep, int *i)
{
	int	j;

	j = 0;
	while (sep[j] != '\0')
	{
		res[*i + j] = sep[j];
		j++;
	}
	*i += j;
}

char	*ft_strsuperjoin(char *s1, char *s2, char *sep)
{
	int		i;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ ft_strlen(sep) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	add_after_i(res, s1, &i);
	add_after_i(res, sep, &i);
	add_after_i(res, s2, &i);
	res[i] = '\0';
	return (res);
}
