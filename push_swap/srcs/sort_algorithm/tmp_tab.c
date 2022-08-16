/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:25:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/16 12:53:09 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	filling_tab(t_stack *lst)
{
	int	i;

	i = 0;
	while (i < lst->len_a)
	{
		lst->sort_tab[i] = lst->stack_a[i];
		i++;
	}
}

void	sort_tmp_tab(t_stack *lst)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < lst->len_a - 1)
	{
		j = i + 1;
		while (j < lst->len_a)
		{
			if (lst->sort_tab[i] > lst->sort_tab[j])
			{
				swap = lst->sort_tab[i];
				lst->sort_tab[i] = lst->sort_tab[j];
				lst->sort_tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}
