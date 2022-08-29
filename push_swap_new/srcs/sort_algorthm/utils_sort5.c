/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:07:28 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 16:04:45 by ngrenoux         ###   ########.fr       */
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
		if (position < mid)
			rotate_a(lst);
		else
			reverse_rot_a(lst);
		position = search_pos_min(lst, len);
	}
}
