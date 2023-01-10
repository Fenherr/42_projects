/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpler_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:23:52 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/19 11:37:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*simpler_gnl(int fd)
{
	int		i;
	int		rd;
	char	c;
	char	*buff;

	i = 0;
	rd = 1;
	c = '\0';
	buff = ft_calloc(sizeof(char), 10000);
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		buff[i] = '\0';
		buff[i++] = c;
		if (c == '\n')
			break ;
	}
	if ((!buff[i - 1] && !rd) || rd == -1)
	{
		free(buff);
		return (NULL);
	}
	buff[i] = '\0';
	return (buff);
}
