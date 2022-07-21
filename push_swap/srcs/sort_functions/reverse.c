/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:17:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/21 09:29:04 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void reverse_rot_a(t_stack *lst)
{
	int tmp;
	int i;

	i = lst->len_a;
	tmp = lst->stack_a[lst->len_a - 1];
	while (i > 0)
	{
		lst->stack_a[i] = lst->stack_a[i - 1];
		i--;
	}
	lst->stack_a[0] = tmp;
}

void reverse_rot_b(t_stack *lst)
{
	int tmp;
	int i;

	i = lst->len_b;
	tmp = lst->stack_b[lst->len_b - 1];
	while (i > 0)
	{
		lst->stack_b[i] = lst->stack_b[i - 1];
		i--;
	}
	lst->stack_b[0] = tmp;
}