/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:00:30 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/04 14:42:05 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*clear_and_return(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*actual;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	res = ft_lstnew((*f)(lst->content));
	if (res == NULL)
		return (NULL);
	actual = lst->next;
	while (actual != NULL)
	{
		tmp = ft_lstnew((*f)(actual->content));
		if (tmp == NULL)
			return (clear_and_return(res, del));
		ft_lstadd_back(&res, tmp);
		actual = actual->next;
	}
	return (res);
}
