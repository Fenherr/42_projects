/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:35:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/06 14:20:54 by ngrenoux         ###   ########.fr       */
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
		lst->stack_a[i] = ft_atoll(tmp[i]);
		i++;
	}
	free_split(tmp);
	return (lst);
}

static void	filling_stack_utils(int ac, char **av, t_stack *lst, int i)
{
	if (ac == 2)
		{
			if (av[1][0] == '\0')
			{
				free_stack(lst);
				exit(0);
			}
			else if (ft_strchr(av[1], ' '))
				lst = seperate_arg(lst, av[1]);
		}
		else
		{
			if (error(av[i]))
			{
				free_stack(lst);
				exit(0);
			}
			lst->stack_a[i - 1] = ft_atoll(av[i]);
		}
}

void	filling_stack(t_stack *lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		filling_stack_utils(ac, av, lst, i);
		i++;
	}
	is_dup(lst);
}
