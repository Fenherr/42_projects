/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:30:22 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/27 15:31:25 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *lstnew(char *value)
{
	t_stack *new;

	if (error(value) == 1)
		exit(0);
	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = ft_atoi(value);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
