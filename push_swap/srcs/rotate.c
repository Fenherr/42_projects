/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:59:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 17:03:35 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *rotate(t_stack *lst)
{
    t_stack *sec_elm;

    if (!lst)
        return (NULL);
    sec_elm = lst->next;
    sec_elm->prev = NULL;
    addback(lst, lst);
    return (sec_elm);
}