/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:49:10 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/30 15:45:39 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void one_move_swap(t_stack *lst)
{
	t_stack *last;
	t_stack *next_elm;

	last = lstlast(lst);
	next_elm = lst->next;
	if (lst->content > next_elm->content && next_elm->next == NULL)
	{
		swap_elm(lst);
		ft_printf("sa\n");
	}
	else if (lst->content > next_elm->content && lst->content < last->content)
	{
		swap_elm(lst);
		ft_printf("sa\n");
	}
}

void sort3(t_stack *lst)
{
	one_move_swap(lst);
}