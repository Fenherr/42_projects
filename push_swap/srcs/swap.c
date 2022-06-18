/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:48:41 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/18 09:17:16 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*swap(t_stack *lst)
{
	t_stack	*sec_elm;
	t_stack	*th_elm;

	if (!lst || !lst->next)
		return (NULL);
	sec_elm = lst->next;
	if (sec_elm->next != NULL)
	{
		th_elm = sec_elm->next;
		th_elm->prev = lst;
		lst->next = th_elm;
	}
	else
		lst->next = NULL;
	lst->prev = sec_elm;
	sec_elm->next = lst;
	sec_elm->prev = NULL;
	return (sec_elm);
}
