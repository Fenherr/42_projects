/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:36:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 15:05:52 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *lst)
{
	int	i;

	i = 0;
	while (i < lst->len_a - 1)
	{
		if (lst->stack_a[i] > lst->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
