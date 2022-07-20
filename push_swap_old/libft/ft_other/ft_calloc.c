/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:52:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/02 12:22:44 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	arr = malloc(size * nmemb);
	if (!arr || (nmemb * size > 2147483647))
		return (NULL);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}
