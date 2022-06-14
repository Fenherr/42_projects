/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:34 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/31 11:06:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *lastelm(t_stack *lst)
{
	t_stack *last;

	if (!lst)
		return (NULL);
	last = lst;
	while (lst)
	{
		if (last->next == NULL)
			return (last);
		else
			last = last->next;
	}
	return (last);
}

t_stack *reverse_rotate(t_stack *lst)
{
	t_stack *last;
	int i;
	t_stack *tmp;

	i = 1;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	last = tmp;
	last->next = lst;
	tmp = last;
	while (i >= 0)
	{
		lst = lst->next;
		last = last->next;
		last = lst;
		i--;
	}
	lst->next = NULL;
	return (tmp);
}
