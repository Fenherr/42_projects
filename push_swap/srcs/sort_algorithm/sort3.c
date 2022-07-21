/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:53:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/21 14:11:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void one_move(t_stack *lst)
{
	int first;
	int second;
	int third;

	first = lst->stack_a[0];
	second = lst->stack_a[1];
	third = lst->stack_a[lst->len_a];
	if (first > second && third > second && third > first)
	{
		swap_a(lst);
		ft_printf("sa\n");
	}
}

void sort3(t_stack *lst)
{
	one_move(lst);
}