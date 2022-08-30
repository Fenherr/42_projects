/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:47:35 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/30 09:57:38 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stack *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->stack_a[0];
	while (i < lst->len_a - 1)
	{
		lst->stack_a[i] = lst->stack_a[i + 1];
		i++;
	}
	lst->stack_a[i] = tmp;
	ft_printf("ra\n");
}

void	rotate_b(t_stack *lst)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lst->stack_b[0];
	while (i < lst->len_b - 1)
	{
		lst->stack_b[i] = lst->stack_b[i + 1];
		i++;
	}
	lst->stack_b[i] = tmp;
	ft_printf("rb\n");
}
