/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:18:37 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 15:06:00 by ngrenoux         ###   ########.fr       */
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
