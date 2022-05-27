/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/23 15:41:22 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*init(int val)
{
	t_lst	*lst;
	t_stack	*elm;

	lst = malloc(sizeof(*lst));
	elm = malloc(sizeof(*elm));
	if (!lst || !elm)
		return (NULL);
	elm->value = val;
	elm->next = NULL;
	lst->first = elm;
	return (lst);
}
