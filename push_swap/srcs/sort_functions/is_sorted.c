/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:48:50 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/26 15:29:00 by ngrenoux         ###   ########.fr       */
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