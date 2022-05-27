/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:16:33 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/23 15:40:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_lst *lst, int val)
{
	t_stack	*pos;
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->value = val;
	new->next = NULL;
	if (lst->first != NULL)
	{
		pos = lst->first;
		while (pos->next != NULL)
			pos = pos->next;
		pos->next = new;
	}
	else
		lst->first = new;
}

void	add_front(t_lst *lst, int val)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->value = val;
	new->next = lst->first;
	lst->first = new;
}
