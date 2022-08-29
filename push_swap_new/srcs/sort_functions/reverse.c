/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:47:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 16:16:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rot_a(t_stack *lst)
{
	int	tmp;
	int	i;

	i = lst->len_a;
	tmp = lst->stack_a[lst->len_a - 1];
	while (i > 0)
	{
		lst->stack_a[i] = lst->stack_a[i - 1];
		i--;
	}
	lst->stack_a[0] = tmp;
	ft_printf("rra\n");
	lstaff(lst);
}

void	reverse_rot_b(t_stack *lst)
{
	int	tmp;
	int	i;

	i = lst->len_b;
	tmp = lst->stack_b[lst->len_b - 1];
	while (i > 0)
	{
		lst->stack_b[i] = lst->stack_b[i - 1];
		i--;
	}
	lst->stack_b[0] = tmp;
	ft_printf("rrb\n");
	lstaff(lst);
}
