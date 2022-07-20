/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:18:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/18 15:17:15 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int lstsize(t_stack *lst)
{
	size_t i;

	i = 0;
	while ((lst)->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void sort(t_stack *lst)
{
	if (lstsize(lst) <= 3 && lstsize(lst) > 1)
		sort3(&lst);
	else if (lstsize(lst) > 3 && lstsize(lst) <= 5)
		sort5(&lst);
}
