/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:20 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/16 14:07:18 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort100(t_stack *lst)
{
	int	i;
	int	med1;
	int	med2;

	i = 0;
	filling_tab(lst);
	sort_tmp_tab(lst);
	med1 = lst->sort_tab[lst->len_a / 3];
	med2 = lst->sort_tab[2 * (lst->len_a / 3)];
	while (i < lst->len_a)
	{
		if (lst->stack_a[i] < med1)
		{
			ft_printf("%d\n", lst->stack_a[i]);
		}
		else if (lst->stack_a[i] >= med1 && lst->stack_a[i] < med2)
		{
			
		}
		else
		{
			
		}
		i++;
	}
}
