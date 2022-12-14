/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:50:47 by aderouba          #+#    #+#             */
/*   Updated: 2022/09/30 15:58:03 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*actual;

	if (lst == NULL || f == NULL)
		return ;
	actual = lst;
	while (actual != NULL)
	{
		(*f)(actual->content);
		actual = actual->next;
	}
}
