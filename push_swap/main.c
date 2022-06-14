/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:38:47 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/10 12:49:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int i;
	t_stack *a;
	t_stack *b;

	i = 1;
	a = init(ft_atoi(av[i]));
	b = NULL;
	if (error(av[i]) == 1)
		exit(0);
	while (++i < ac)
	{
		if (error(av[i]) == 0)
			add_back(a, ft_atoi(av[i]));
		else
			exit(0);
	}
	is_dup(a);
	print_stack(a, b);
	ft_printf("--a--\n");
	reverse_rotate(a);
	print_stack(a, b);
	return (0);
}
