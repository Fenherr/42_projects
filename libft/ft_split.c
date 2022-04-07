/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:26:47 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/07 17:37:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countlines(char const *s, char c)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1]))
			cpt++;
		i++;
	}
	return (cpt);
}

/*static void	ft_fill(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			arr[j][k] = s[i];
			i++;
			k++;
		}
		while (s[i] == c && s[i])
			i++;
		arr[j][k] = 0;
		j++;
	}
	arr[j] = NULL;
}*/

static void	ft_free(char **arr, int j)
{
	while (j-- > 0)
		free(arr[j]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	line;
	size_t	count;

	arr = malloc(sizeof(char *) * (ft_countlines(s, c) + 1));
	if (!arr)
		return (arr = ft_calloc(sizeof(char), 1));
	i = 0;
	line = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		count = 1;
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		arr[line] = ft_substr(s, i, count - 1);
		if (!arr[line])
		{
			ft_free(arr, line);
			return (arr = ft_calloc(sizeof(char), 1));
		}
		line++;
	}
	//ft_fill(s, c, arr);
	return (arr);
}
