/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:18:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/01 12:19:37 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push(t_stack *a, t_stack *b)
{
	if (!a)
		return (NULL);
	if (!b)
		a->next = NULL;
	else
		a->next = b;
	return (a);
}
