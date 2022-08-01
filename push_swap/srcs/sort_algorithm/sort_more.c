/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:38:37 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/01 14:55:13 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_more(t_stack *lst)
{
	while (lst->len_a != 1)
	{
		min_to_first_pos(lst);
		push_b(lst);
		ft_printf("pb\n");
	}
	while (lst->len_b != 0)
	{
		push_a(lst);
		ft_printf("pa\n");
	}
}