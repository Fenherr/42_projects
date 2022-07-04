/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:37:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/04 14:21:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int check_if_first_is_min(t_stack *lst)
{
	t_stack *tmp;

	tmp = lst;
	lst = lst->next;
	while (lst)
	{
		if (tmp->content < lst->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}