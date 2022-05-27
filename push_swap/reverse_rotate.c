/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:32:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/25 15:15:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lastelm(t_lst *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst->first;
	while (lst)
	{
		if (last->next == NULL)
			return (last);
		else
			last = last->next;
	}
	return (last);
}

void	reverse_rotate(t_lst *lst)
{
	t_stack	*last;

	if (!lst)
		return ;
	last = lastelm(lst);
	
}
