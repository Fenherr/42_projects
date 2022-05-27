/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:28:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/23 15:41:56 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_lst *lst)
{
	t_stack	*l;

	if (!lst)
		return ;
	l = lst->first;
	while (l)
	{
		ft_printf("%d\n", l->value);
		l = l->next;
	}
}
