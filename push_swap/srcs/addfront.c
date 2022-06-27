/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfront.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:08:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/27 13:53:01 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void addfront(t_stack *lst, t_stack *new)
{
	if (!lst || !new)
		return;
	new->next = lst;
	new->prev = NULL;
	lst->prev = new;
}
