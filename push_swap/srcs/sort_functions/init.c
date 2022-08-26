/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:27:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/23 10:05:25 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init(int ac)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	lst->len_a = ac - 1;
	lst->len_b = 0;
	lst->stack_a = ft_calloc(sizeof(int), lst->len_a);
	lst->stack_b = ft_calloc(sizeof(int), lst->len_a);
	lst->sort_tab = ft_calloc(sizeof(int), lst->len_a);
	lst->index = ft_calloc(sizeof(int), lst->len_a);
	return (lst);
}
