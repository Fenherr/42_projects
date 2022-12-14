/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supersplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:55:13 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/21 11:38:31 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_sep(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep && sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_supersplit(char const *s, char *sep)
{
	int		i;
	int		j;
	char	**res;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[0] = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		while (is_in_sep(sep, s[i]))
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (is_in_sep(sep, s[i + j]) && s[i + j] != '\0')
			j++;
		res = ft_add_str(res, ft_substr(s, i, j));
		i += j;
	}
	return (res);
}
