/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:29:55 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/11 16:20:16 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_stack *lst)
{
	if (lst->len_a <= 3)
		sort3(lst);
	else if (lst->len_a >= 4 && lst->len_a <= 5)
		sort5(lst);
	else if (lst->len_a > 5)
		sort100(lst);
}