/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:20 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/26 15:31:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_replacement(t_stack *lst)
{
	int	i;

	i = 0;
	filling_index(lst);
	while(i <lst->len_a)
	{
		lst->stack_a[i] = lst->index[i];
		i++;
	}
}

void	sort100(t_stack *lst)
{
	int	i;
	int	mask;
	int	len;

	mask = 0;
	len = lst->len_a;
	while (mask < 32)
	{
		i = 0;
		while (i < len)
		{
			if (!(lst->stack_a[0] & (1 << mask)))
				push_b(lst);
			else
				rotate_a(lst);
			i++;
		}
		while (lst->len_b > 0)
			push_a(lst);
		if(is_sorted(lst) == 1)
			return ;
		mask++;
	}
}
