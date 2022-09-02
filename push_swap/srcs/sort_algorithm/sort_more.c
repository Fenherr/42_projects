/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:02:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/01 12:36:00 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	stack_replacement(t_stack *lst)
{
	int	i;

	i = 0;
	filling_index(lst);
	while (i < lst->len_a)
	{
		lst->stack_a[i] = lst->index_tab[i];
		i++;
	}
}

static void	radix(t_stack *lst, int len, int mask)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (lst->stack_a[0] & (1 << mask))
			rotate_a(lst);
		else
			push_b(lst);
		i++;
	}
	while (lst->len_b > 0)
		push_a(lst);
}

void	sort_more(t_stack *lst)
{
	int	len;
	int	mask;

	mask = 0;
	len = lst->len_a;
	stack_replacement(lst);
	while (!is_sorted(lst))
	{
		radix(lst, len, mask);
		mask++;
	}
}
