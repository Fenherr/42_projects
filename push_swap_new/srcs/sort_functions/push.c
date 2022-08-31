/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:41:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/31 13:15:08 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b(t_stack *lst)
{
	int	i;
	int	j;

	i = -1;
	j = lst->len_b + 1;
	if (lst->len_a != 0)
	{
		lst->len_b++;
		if (lst->stack_b[0] == 0)
			lst->stack_b[0] = lst->stack_a[0];
		else
		{
			while (j-- > 0)
				lst->stack_b[j] = lst->stack_b[j - 1];
			lst->stack_b[0] = lst->stack_a[0];
		}
		while (i++ < lst->len_a - 1)
			lst->stack_a[i] = lst->stack_a[i + 1];
		lst->len_a--;
	}
	ft_printf("pb\n");
}

void	push_a(t_stack *lst)
{
	int	i;
	int	j;

	i = -1;
	j = lst->len_a + 1;
	if (lst->len_b != 0)
	{
		lst->len_a++;
		if (lst->stack_a[0] == 0)
			lst->stack_a[0] = lst->stack_b[0];
		else
		{
			while (j-- > 0)
				lst->stack_a[j] = lst->stack_a[j - 1];
			lst->stack_a[0] = lst->stack_b[0];
		}
		while (i++ < lst->len_b - 1)
			lst->stack_b[i] = lst->stack_b[i + 1];
		lst->len_b--;
	}
	ft_printf("pa\n");
}
