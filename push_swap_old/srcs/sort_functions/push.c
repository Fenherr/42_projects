/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:13:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/30 15:20:12 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	tmp = *src;
	if (!*src)
		return;
	if (!*dest)
		*dest = lstnew((*src)->content);
	else
		addfront(dest, lstnew((*src)->content));
	*src = (*src)->next;
	(*src)->prev = NULL;
	free(tmp);
}
