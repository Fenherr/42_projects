/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:35:24 by aderouba          #+#    #+#             */
/*   Updated: 2022/09/30 13:39:10 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*actual;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	actual = *lst;
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = new;
}
