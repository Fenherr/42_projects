/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:26:47 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/06 12:59:19 by ngrenoux         ###   ########.fr       */
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
	return (cpt + 1);
}

static void	ft_fill(char const *s, char c, char **tab)
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
			tab[j][k] = s[i];
			i++;
			k++;
		}
		while (s[i] == c && s[i])
			i++;
		tab[j][k] = 0;
		j++;
	}
	tab[j] = NULL;
}

static void	ft_malloccount(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	line;
	size_t	count;

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
		arr[line] = malloc(sizeof(char) * count);
		line++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr;

	i = ft_countlines(s, c);
	arr = malloc(sizeof(char *) * i);
	if (!s)
		return (arr);
	ft_malloccount(s, c, arr);
	ft_fill(s, c, arr);
	return (arr);
}
