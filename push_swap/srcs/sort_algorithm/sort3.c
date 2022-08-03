/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:53:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/03 12:52:37 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	one_move_swap(t_stack *lst)
{
	int	first;
	int	second;
	int	third;

	first = lst->stack_a[0];
	second = lst->stack_a[1];
	third = lst->stack_a[2];
	if ((lst->len_a == 2 && first > second)
		|| (first > second && third > second && third > first))
	{
		swap_a(lst);
		ft_printf("sa\n");
	}
}

static void	one_move_rotate(t_stack *lst)
{
	int	first;
	int	second;
	int	third;

	first = lst->stack_a[0];
	second = lst->stack_a[1];
	third = lst->stack_a[2];
	if (lst->len_a == 3)
	{
		if (first > second && first > third && second < third)
		{
			rotate_a(lst);
			ft_printf("ra\n");
		}
		else if (first > third && second > first && second > third)
		{
			reverse_rot_a(lst);
			ft_printf("rra\n");
		}
	}
}

static void	two_move(t_stack *lst)
{
	int	first;
	int	second;
	int	third;

	first = lst->stack_a[0];
	second = lst->stack_a[1];
	third = lst->stack_a[2];
	if (lst->len_a == 3)
	{
		if ((first > second && second > third)
			|| (second > first && second > third && third > first))
		{
			swap_a(lst);
			ft_printf("sa\n");
			one_move_rotate(lst);
		}
	}
}

void	sort3(t_stack *lst)
{
	one_move_swap(lst);
	one_move_rotate(lst);
	two_move(lst);
}
