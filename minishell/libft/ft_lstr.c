/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:46:31 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/17 13:13:54 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_str(char **lstr, char *str)
{
	int		i;
	char	**res;

	i = 0;
	while (lstr[i] != NULL)
		i++;
	res = malloc(sizeof(char *) * (i + 2));
	if (res == NULL)
		return (lstr);
	i = 0;
	while (lstr[i] != NULL)
	{
		res[i] = lstr[i];
		i++;
	}
	res[i] = str;
	res[i + 1] = NULL;
	free(lstr);
	return (res);
}

void	ft_put_lstr_fd(char **lstr, int fd)
{
	int	i;

	i = 0;
	while (lstr && lstr[i])
	{
		ft_putendl_fd(lstr[i], fd);
		i++;
	}
}

void	ft_lstr_free(char **lstr)
{
	int	i;

	i = 0;
	while (lstr && lstr[i])
	{
		free(lstr[i]);
		i++;
	}
	if (lstr)
		free(lstr);
}
