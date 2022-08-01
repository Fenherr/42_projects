/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:53:44 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/01 14:04:32 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort4(t_stack *lst)
{
	push_b(lst);
	ft_printf("pb\n");
	sort3(lst);
	push_a(lst);
	ft_printf("pa\n");
}

void sort5(t_stack *lst)
{
	min_to_first_pos(lst);
	if (lst->len_a == 4)
		sort4(lst);
	else if (lst->len_a == 5)
	{
		push_b(lst);
		ft_printf("pb\n");
		min_to_first_pos(lst);
		sort4(lst);
		push_a(lst);
		ft_printf("pa\n");
	}
}