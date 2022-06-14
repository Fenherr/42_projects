/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:13:30 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 17:16:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *push(t_stack *a, t_stack *b)
{
    if (!a)
        return (NULL);
    if (!b)
    {
        a->next = NULL;
        a->prev = NULL;
        return (a);
    }
    else
    {
        a->prev = NULL;
        a->next = b;
        b->prev = a;
        return (a);
    }
}