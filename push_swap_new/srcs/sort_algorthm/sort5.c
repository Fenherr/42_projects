/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:08:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 15:08:19 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort4(t_stack *lst)
{
	push_b(lst);
	sort3(lst);
	push_a(lst);
}

void	sort5(t_stack *lst)
{
	min_to_first_pos(lst, lst->len_a);
	if (lst->len_a == 4)
		sort4(lst);
	else if (lst->len_a == 5)
	{
		push_b(lst);
		min_to_first_pos(lst, lst->len_a);
		sort4(lst);
		push_a(lst);
	}
}
