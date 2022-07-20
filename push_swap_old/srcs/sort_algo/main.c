/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:25:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/18 15:15:02 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ft_affiche(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
}

int main(int ac, char **av)
{
	int i;
	t_stack *lst;

	i = 1;
	if (ac >= 2)
	{
		if (error(av[i]) == 1)
			exit(0);
		lst = lstnew(ft_atoi(av[1]));
		while (++i < ac)
		{
			if (error(av[i]) == 1)
				exit(0);
			else
				addback(lst, lstnew(ft_atoi(av[i])));
		}
		is_dup(lst);
		sort(lst);
		ft_affiche(lst);
	}
}
