/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:18:37 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/01 14:22:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack *lst)
{
	free(lst->index_tab);
	free(lst->stack_a);
	free(lst->stack_b);
	free(lst->tmp_tab);
	free(lst);
}

void	free_split(char **arg_split)
{
	int	i;

	i = 0;
	while (arg_split[i])
	{
		free(arg_split[i]);
		i++;
	}
	free(arg_split);
}