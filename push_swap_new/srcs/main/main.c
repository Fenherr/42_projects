/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:42:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/31 14:31:15 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	free_stack(lst);
	return (0);
}
