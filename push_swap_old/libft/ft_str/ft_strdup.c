/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:01:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:10:04 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		count;

	count = ft_strlen(s);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, count + 1);
	return (str);
}
