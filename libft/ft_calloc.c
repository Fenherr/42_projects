/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:52:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/01 11:09:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.c"

void	*calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	while (i++ < nmemb)
		tab = malloc(sizeof(size))
	return (tab);
}
