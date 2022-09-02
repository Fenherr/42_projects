/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:51:11 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/31 13:15:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort4(t_stack *lst)
{
	min_to_first_pos(lst);
	push_b(lst);
	sort3(lst);
	push_a(lst);
}

void	sort5(t_stack *lst)
{
	min_to_first_pos(lst);
	push_b(lst);
	sort4(lst);
	push_a(lst);
}
