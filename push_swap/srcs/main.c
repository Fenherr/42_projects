/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:25:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/28 11:44:28 by ngrenoux         ###   ########.fr       */
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

	i = 1;
	if (ac >= 2)
	{
		if (error(av[i]) == 1)
			exit(0);
		lst = lstnew(ft_atoi(av[1]));
		tmp = NULL;
		while (++i < ac)
		{
			if (error(av[i]) == 1)
				exit(0);
			else
				addback(lst, lstnew(ft_atoi(av[i])));
		}
		is_dup(lst);
		ft_affiche(lst);
		ft_printf("-Original stack-\n\n");
		push(lst, &tmp);
		ft_affiche(tmp);
		ft_printf("-Stack b-\n\n");
		ft_affiche(lst);
		ft_printf("-Stack a-\n");
	}
}