/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:49:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/12 08:43:41 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*find_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static int	rd;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, buff, BUFFER_SIZE);
	if (rd < 0)
		return (NULL);
	find_line(buff);
	buff[rd] = '\0';
	return (buff);
}

int	main()
{
	int	fd;

	fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
}
