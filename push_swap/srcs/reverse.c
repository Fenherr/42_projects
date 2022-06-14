/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:05:21 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 17:11:48 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *reverse(t_stack *lst)
{
    t_stack *last;
    t_stack *before_last;

    if(!lst)
        return (NULL);
    last = lstlast(lst);
    before_last = last->prev;
    addfront(lst, last);
    before_last->next = NULL;
    return (last);
}