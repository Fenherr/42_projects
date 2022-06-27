/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:25:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/27 15:45:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_stack *tmp;

	i = 2;
	if (ac >= 2)
	{
		lst = lstnew(av[1]);
		tmp = NULL;
		while (i < ac)
		{
			if (error(av[i]) == 1)
				exit(0);
			else
				addback(lst, lstnew(av[i]));
			i++;
		}
		is_dup(lst);
		ft_affiche(lst);
		ft_printf("\n");
		tmp = push(lst, tmp);
		ft_affiche(tmp);
		ft_printf("-Stack b-\n");
		ft_affiche(lst);
		ft_printf("-Stack a-\n");
	}
}