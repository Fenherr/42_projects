/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:22:00 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/31 14:11:44 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_stack *lst, int value)
{
	t_stack	*pos;
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->next = NULL;
	new->content = value;
	if (lst != NULL)
	{
		pos = lst;
		while (pos->next != NULL)
			pos = pos->next;
		pos->next = new;
	}
	else
		lst = new;
}
