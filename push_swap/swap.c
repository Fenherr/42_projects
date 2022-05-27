/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:46:09 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/23 15:44:00 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	lstswap(t_lst *lst)
{
	t_stack	*l;

	l = lst->first->next;
	swap(&lst->first->value, &l->value);
}

void	double_swap(t_lst *a, t_lst *b)
{
	lstswap(a);
	lstswap(b);
}
