/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:20 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/04 15:21:48 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort100(t_stack *lst)
{
	int	i;
	int	j;
	int	part_len;
	
	i = 0;
	j = 0;
	part_len = lst->len_a / 3;
	while (i < lst->len_a)
	{
		min_to_first_pos(lst, part_len);
		if (lst->len_b == 0 || lst->len_b == 1)
		{
			push_b(lst);
			ft_printf("pb\n");
		}
		else
		{
			if (lst->len_b == 2 && lst->stack_b[0] < lst->stack_b[1])
			{
				swap_b(lst);
				ft_printf("sb\n");
			}
			while (i < lst->len_b)
			{
				if (lst->stack_a[0] < lst->stack_b[j])
					j++;
				else
				{
					if (j < lst->len_b / 2)
					{
						while (j != 0)
						{
							rotate_b(lst);
							ft_printf("rb/n");
						}
						j--;
					}
					else
					{
						while (j != 0)
						{
							reverse_rot_b(lst);
							ft_printf("rrb/n");
						}
						j--;
					}
				}
				push_b(lst);
				ft_printf("pb/n");
			}
		}
		i++;
	}
}