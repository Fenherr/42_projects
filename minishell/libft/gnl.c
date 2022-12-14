/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:37:27 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 12:58:11 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*res;
	char	buffer[2];
	int		read_len;

	if (fd < 0)
		return (NULL);
	res = malloc(sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	buffer[0] = '\0';
	buffer[1] = '\0';
	read_len = read(fd, buffer, 1);
	if (read_len <= 0)
	{
		free(res);
		return (NULL);
	}
	while (read_len > 0 && buffer[0] != '\n')
	{
		res = ft_strjoin_free_1st_p(res, buffer);
		read_len = read(fd, buffer, 1);
	}
	res = ft_strjoin_free_1st_p(res, buffer);
	return (res);
}
