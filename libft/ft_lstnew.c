/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:50:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/06 17:03:45 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elm;

	elm = (t_list *)malloc(sizeof(*elm));
	if (!elm)
		return (NULL);
	elm ->content = content;
	elm ->next = NULL;
	return (elm);
}
