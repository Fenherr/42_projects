/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:30:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/23 15:42:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delelm(t_lst *lst)
{
	t_stack	*l;

	if (!lst)
		return ;
	l = lst->first;
	lst->first = lst->first->next;
	free(l);
}

void	rotate(t_lst *lst)
{
	add_back(lst, lst->first->value);
	delelm(lst);
}

void	double_rotate(t_lst *a, t_lst *b)
{
	rotate(a);
	rotate(b);
}
