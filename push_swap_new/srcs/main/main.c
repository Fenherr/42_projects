/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:42:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/30 10:42:46 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	lstaff(t_stack *lst)
{
	int	i;

	i = 0;
	ft_printf("--stack a--\n");
	while (i < lst->len_a)
	{
		ft_printf("%d\n", lst->stack_a[i]);
		i++;
	}
	ft_printf("-----------\n");
}

int	main(int ac, char **av)
{
	t_stack	*lst;

	lst = init(ac, av[1]);
	if (ac >= 2)
	{
		filling_stack(lst, ac, av);
		if (is_sorted(lst) == 0)
			sort(lst);
	}
	//lstaff(lst);
	free_stack(lst);
	return (0);
}
