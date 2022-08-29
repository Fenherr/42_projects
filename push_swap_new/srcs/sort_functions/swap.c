/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:47:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 16:17:05 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack *lst)
{
	int	tmp;

	tmp = lst->stack_a[0];
	lst->stack_a[0] = lst->stack_a[1];
	lst->stack_a[1] = tmp;
	ft_printf("sa\n");
	lstaff(lst);
}

void	swap_b(t_stack *lst)
{
	int	tmp;

	tmp = lst->stack_b[0];
	lst->stack_b[0] = lst->stack_b[1];
	lst->stack_b[1] = tmp;
	ft_printf("sb\n");
	lstaff(lst);
}
