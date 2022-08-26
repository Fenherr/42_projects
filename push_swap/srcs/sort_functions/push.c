/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:32:15 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/26 11:07:26 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b(t_stack *lst)
{
	if (lst->len_a != 0)
	{
		lst->len_b++;
		if (lst->stack_b[0] == 0)
			lst->stack_b[0] = lst->stack_a[0];
		else
		{
			reverse_rot_b(lst);
			lst->stack_b[0] = lst->stack_a[0];
		}
		rotate_a(lst);
		lst->len_a--;
	}
	ft_printf("pb\n");
}

void	push_a(t_stack *lst)
{
	if (lst->len_b != 0)
	{
		lst->len_a++;
		if (lst->stack_a[0] == 0)
			lst->stack_a[0] = lst->stack_b[0];
		else
		{
			reverse_rot_a(lst);
			lst->stack_a[0] = lst->stack_b[0];
		}
		rotate_b(lst);
		lst->len_b--;
	}
	ft_printf("pa\n");
}
