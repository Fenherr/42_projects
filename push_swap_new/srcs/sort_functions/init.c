/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:27:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/06 11:38:51 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init(t_stack *lst, int ac)
{
	lst->len_a = ac - 1;
	lst->len_b = 0;
	lst->stack_a = calloc(sizeof(int), lst->len_a);
	lst->stack_b = calloc(sizeof(int), lst->len_a);
}
