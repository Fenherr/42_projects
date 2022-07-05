/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:49:10 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/05 10:59:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void one_move_swap(t_stack *lst)
{
	t_stack *last;
	t_stack *next_elm;

	last = lstlast(lst);
	next_elm = lst->next;
	if (lst->content > next_elm->content && next_elm->next == NULL)
	{
		swap_elm(lst);
		ft_printf("sa\n");
	}
	else if (lst->content > next_elm->content && lst->content < last->content)
	{
		swap_elm(lst);
		ft_printf("sa\n");
	}
}

static void one_move_rotate(t_stack *lst)
{
	t_stack *last;
	t_stack *next_elm;

	last = lstlast(lst);
	next_elm = lst->next;
	if (lst->content > next_elm->content && next_elm->content < last->content)
	{
		rotate(lst);
		ft_printf("ra\n");
	}
	else if (lst->content < next_elm->content && lst->content > last->content)
	{
		reverse(lst);
		ft_printf("rra\n");
	}
}

static void two_moves(t_stack *lst)
{
	t_stack *last;
	t_stack *next_elm;

	last = lstlast(lst);
	next_elm = lst->next;
	if (lst->content > next_elm->content && next_elm->content > last->content)
	{
		swap_elm(lst);
		ft_printf("sa\n");
		reverse(lst);
		ft_printf("rra\n");
	}
	else if (lst->content < next_elm->content && next_elm->content > last->content)
	{
		swap_elm(lst);
		ft_printf("sa\n");
		rotate(lst);
		ft_printf("ra\n");
	}
}

void sort3(t_stack **lst)
{
	one_move_swap(*lst);
	one_move_rotate(*lst);
	two_moves(*lst);
}