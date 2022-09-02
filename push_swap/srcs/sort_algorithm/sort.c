/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:58:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/31 13:05:16 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_stack *lst)
{
	if (lst->len_a <= 3)
		sort3(lst);
	else if (lst->len_a == 4)
		sort4(lst);
	else if (lst->len_a == 5)
		sort5(lst);
	else if (lst->len_a > 5)
		sort_more(lst);
}
