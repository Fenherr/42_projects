/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:26:47 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/21 12:41:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int ft_countline(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static int ft_ilen(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void ft_niel(char **str, int i)
{
	while (i-- > 0)
		free(str[i]);
	free(str);
}

char **ft_split(char const *s, char c)
{
	int i;
	int j;
	char **str;

	i = 0;
	j = -1;
	str = malloc((ft_countline(s, c) + 1) * sizeof(char *));
	if (!str)
		return (str = ft_calloc(sizeof(char), 1));
	while (++j < ft_countline(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, ft_ilen(s, c, i));
		str[j][ft_ilen(s, c, i)] = 0;
		if (!str[j])
		{
			ft_niel(str, j);
			return (str = ft_calloc(sizeof(char), 1));
		}
		i += ft_ilen(s, c, i);
	}
	str[j] = NULL;
	return (str);
}
