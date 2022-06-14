/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:30:22 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 16:45:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *lstnew(char *value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new->content = ft_atoi(value);
    new->next = NULL;
    new->prev = NULL;
    return (new);
}