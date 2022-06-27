/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:05:21 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/27 15:18:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void reverse_swap(t_stack *lst)
{
	t_stack *prev_elm;

	prev_elm = lst->prev;
	swap(&lst->content, &prev_elm->content);
}

void reverse(t_stack *lst)
{
	lst = lstlast(lst);
	while (lst->prev)
	{
		reverse_swap(lst);
		lst = lst->prev;
	}
}
