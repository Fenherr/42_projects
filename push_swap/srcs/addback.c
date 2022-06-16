/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:09:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 18:09:41 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last)
	{
		if (last->next == NULL)
			return (last);
		else
			last = last->next;
	}
	return (last);
}

t_stack	*addback(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lstlast(lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
	return (lst);
}
