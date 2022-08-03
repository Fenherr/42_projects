/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:02:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/03 12:45:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack *lst)
{
	int	tmp;

	tmp = lst->stack_a[0];
	lst->stack_a[0] = lst->stack_a[1];
	lst->stack_a[1] = tmp;
}

void	swap_b(t_stack *lst)
{
	int	tmp;

	tmp = lst->stack_b[0];
	lst->stack_b[0] = lst->stack_b[1];
	lst->stack_b[1] = tmp;
}
