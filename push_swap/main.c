/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:56:11 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/24 09:37:37 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_lst	*a;
	int		i;

	i = 1;
	a = init(ft_atoi(av[i]));
	while (++i < ac)
		add_back(a, ft_atoi(av[i]));
	print_stack(a);
	ft_printf("----a----");
	lstswap(a);
	ft_printf("\n");
	print_stack(a);
	ft_printf("----a----");
	rotate(a);
	rotate(a);
	ft_printf("\n");
	print_stack(a);
	ft_printf("----a----");
	reverse_rotate(a);
	reverse_rotate(a);
	ft_printf("\n");
	print_stack(a);
	ft_printf("----a----");
	return (0);
}
