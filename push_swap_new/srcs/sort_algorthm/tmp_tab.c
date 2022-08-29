/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:59:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 15:05:27 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	filling_tab(t_stack *lst)
{
	int	i;

	i = 0;
	while (i < lst->len_a)
	{
		lst->tmp_tab[i] = lst->stack_a[i];
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
			if (lst->tmp_tab[i] > lst->tmp_tab[j])
			{
				swap = lst->index_tab[i];
				lst->tmp_tab[i] = lst->tmp_tab[j];
				lst->tmp_tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	filling_index(t_stack *lst)
{
	int	i;
	int	j;

	i = 0;
	filling_tab(lst);
	sort_tmp_tab(lst);
	while (i < lst->len_a)
	{
		j = 0;
		while (j < lst->len_a)
		{
			if (lst->stack_a[i] == lst->tmp_tab[j])
				lst->index_tab[i] = j;
			j++;
		}
		i++;
	}
}
