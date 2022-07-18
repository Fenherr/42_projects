/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:30:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/18 15:17:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort5(t_stack **lst)
{
	t_stack *stack_b;

	stack_b = NULL;
	if (check_if_first_is_min(lst) == 1)
	{
		push(lst, &stack_b);
	}
}