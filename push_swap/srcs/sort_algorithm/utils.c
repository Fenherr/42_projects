/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:31:44 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/04 13:08:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	search_pos_min(t_stack *lst, int len)
{
	int	pos;
	int	i;
	int	tmp;

	i = 0;
	pos = 0;
	tmp = lst->stack_a[i];
	while (i < len)
	{
		if (lst->stack_a[i] < tmp)
		{
			tmp = lst->stack_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	min_to_first_pos(t_stack *lst, int len)
{
	int	mid;
	int	position;

	mid = lst->len_a / 2;
	position = search_pos_min(lst, len);
	while (position != 0)
	{
		if (position <= mid)
		{
			rotate_a(lst);
			ft_printf("ra\n");
		}
		else
		{
			reverse_rot_a(lst);
			ft_printf("rra\n");
		}
		position = search_pos_min(lst, len);
	}
}
