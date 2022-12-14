/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:47:27 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/24 12:01:06 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	actual = *lst;
	while (actual->next != NULL)
	{
		next = actual->next;
		ft_lstdelone(actual, del);
		actual = next;
	}
	ft_lstdelone(actual, del);
	*lst = NULL;
}
