/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:38:47 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/01 13:54:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*keep;

	i = 1;
	a = init(ft_atoi(av[i]));
	b = NULL;
	while (++i < ac)
	{
		if (error(av[i]) == 1)
		{
			ft_printf("Error\n");
			exit(0);
		}
		else
			add_back(a, ft_atoi(av[i]));
	}
	print_stack(a, b);
	ft_printf("--a--\n");
	lst_swap(a);
	print_stack(a, b);
	ft_printf("--sa--\n");
	a = rotate(a);
	print_stack(a, b);
	ft_printf("--ra--\n");
	a = reverse_rotate(a);
	print_stack(a, b);
	ft_printf("--rra--\n");
	keep = a->next;
	b = push(a, b);
	a = keep;
	print_stack(a, b);
	ft_printf("--pb--\n");
	keep = b->next;
	a = push(b, a);
	b = keep;
	print_stack(a, b);
	ft_printf("--pa--");
	return (0);
}
