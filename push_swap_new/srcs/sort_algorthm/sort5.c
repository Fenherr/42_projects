/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:51:11 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/30 11:09:46 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort4(t_stack *lst)
{
	min_to_first_pos(lst);
	push_b(lst);
	// sort3(lst);
	push_a(lst);
}
