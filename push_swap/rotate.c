/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:09:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/30 14:23:55 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*delelm(t_stack *lst)
{
	t_stack	*l;

	if (!lst)
		return (NULL);
	l = lst;
	lst = lst->next;
	free(l);
	return (lst);
}

t_stack	*rotate(t_stack *lst)
{
	t_stack	*keep;

	keep = lst->next;
	add_back(lst, lst->content);
	delelm(lst);
	return (keep);
}
