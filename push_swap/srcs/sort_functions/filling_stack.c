/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:35:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/01 14:31:55 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*seperate_arg(t_stack *lst, char *av)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(av, ' ');
	while (tmp[i])
	{
		if (error(tmp[i]))
		{
			free_split(tmp);
			free_stack(lst);
			exit(0);
		}
		lst->stack_a[i] = ft_atoi(tmp[i]);
		i++;
	}
	free_split(tmp);
	return (lst);
}

void	filling_stack(t_stack *lst, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ac == 2)
		{
			if (av[1][0] == '\0')
				exit(0);
			else if (ft_strchr(av[1], ' '))
				lst = seperate_arg(lst, av[1]);
		}
		else
		{
			error(av[i]);
			lst->stack_a[i - 1] = ft_atoi(av[i]);
		}
	}
	is_dup(lst);
}
