/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:02:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/30 14:57:10 by ngrenoux         ###   ########.fr       */
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
		if (!(lst->stack_a[0] & (1 << mask)))
		{
			push_b(lst);
			ft_printf("pb\n");
		}
		else
		{
			rotate_a(lst);
			ft_printf("ra\n");
		}
		i++;
	}
	while (lst->len_b > 0)
	{
		push_a(lst);
		ft_printf("pa\n");
	}
	if (is_sorted(lst) == 1)
		return ;
}

void	sort_more(t_stack *lst)
{
	int	len;
	int	mask;
	
	mask = 0;
	len = lst->len_a - 1;
	stack_replacement(lst);
	while (mask < 32)
	{
		radix(lst, len, mask);
		mask++;
	}
}