/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfront.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:08:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/30 15:19:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void addfront(t_stack **dest, t_stack *new)
{
	new->next = *dest;
	new->prev = NULL;
	*dest = new;
}
