/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:24:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/31 15:49:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	len_stack(int ac, char *av)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (ac == 2)
	{
		if (check_space(av))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		else
		{
			while (av[i])
			{
				if (av[i] == ' ')
					len++;
				i++;
			}
			return (len + 1);
		}
	}
	return (ac - 1);
}

t_stack	*init(int ac, char *av)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	lst->len_a = len_stack(ac, av);
	lst->len_b = 0;
	lst->stack_a = ft_calloc(sizeof(int), lst->len_a);
	lst->stack_b = ft_calloc(sizeof(int), lst->len_a);
	lst->tmp_tab = ft_calloc(sizeof(int), lst->len_a);
	lst->index_tab = ft_calloc(sizeof(int), lst->len_a);
	return (lst);
}
