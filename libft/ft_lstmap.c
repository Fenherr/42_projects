/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:22:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/07 16:49:46 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	if (!lst)
		return (NULL);
	tmp = lst;
	begin = ft_lstnew((*f)(tmp->content));
	if (!begin)
		return (NULL);
	tmp = tmp->next;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		new = ft_lstnew((*f)(tmp->content));
		if (!new)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		tmp = tmp->next;
	}
	return (begin);
}
