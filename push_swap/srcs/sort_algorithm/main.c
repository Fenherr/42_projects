/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:34:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/19 11:25:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void lstaff(t_stack *lst)
{
	int i;

	i = 0;
	while (i < lst->len_a)
	{
		ft_printf("%d\n", lst->stack_a[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_stack *lst;
	int i;

	i = 0;
	if (ac >= 2)
	{
		lst = init(ac);
		while (++i < ac)
		{
			error(av[i]);
			lst->stack_a[i - 1] = ft_atoi(av[i]);
		}
	}
	is_dup(lst);
	lstaff(lst);
	return (0);
}