/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:52:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/07 17:19:18 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	
	if(nmemb <= 65535 && size <= 65535)
		arr = malloc(size * nmemb);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

