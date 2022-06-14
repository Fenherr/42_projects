/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:35:42 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/31 12:59:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	while (a)
	{
		if (a != NULL && b == NULL)
		{
			ft_printf("%d\n", a->content);
			a = a->next;
		}
		else if (b != NULL && a == NULL)
		{
			ft_printf("%d\n", b->content);
			b = b->next;
		}
		else
		{
			ft_printf("%d	%d\n", a->content, b->content);
			a = a->next;
			b = b->next;
		}
	}
}
